// Treee Traversals
# include <stdio.h>
# include <stdlib.h>
# define LEFT 'l'
# define RIGHT 'r'

// Binary Node
struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

// Initialise a Binary Tree
struct BinaryTreeNode* get_new_node (int data){

    struct BinaryTreeNode *new_node = malloc (sizeof(struct BinaryTreeNode));

    if(!new_node) printf("\nNO MEMORY\n");

    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

// Insert an element in the binary tree
// return root after modifying
// If cannot insert, exit silently
struct BinaryTreeNode* insert_node(struct BinaryTreeNode *root, int node_data, int parent_data, char left_or_right) {

    
    // Check if left or right indicator is okay or not
    if(left_or_right != LEFT && left_or_right != RIGHT){
        printf("ERROR!! False character inserted for left/right indicator\n");
        exit(EXIT_FAILURE);
    }

    // Handle base case, try to insert in tree
    if(!root){
        return root;
    }

    // Search for node and then insert accordingly
    if(root -> data == parent_data){
        if(left_or_right == LEFT){
            root -> left = get_new_node(node_data);
        } else {
            root -> right = get_new_node(node_data);
        }
        return root;
    }

    // Try to insert in left tree
    root -> left = insert_node(root -> left, node_data, parent_data, left_or_right);
    root -> right = insert_node(root -> right, node_data, parent_data, left_or_right);

    return root;
}

// Print Tree function to print the tree
void print_tree(struct BinaryTreeNode *root, int offset){
    int i;
    if(root == NULL) {
        return;
    }

    print_tree(root -> right, offset + 1);
    for(i = 0; i < offset; ++i) printf("\t");
    printf("%d\n", root -> data);
    print_tree(root->left, offset + 1);
}

// DELETION FUNCTION - To delete a node in a binary tree
/*-----------------------------------------------------*/

// Returns the INORDER SUCCESSOR of a node.
struct BinaryTreeNode* minValueNode(struct BinaryTreeNode* node){
    struct BinaryTreeNode* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Deletes the node
struct BinaryTreeNode* deleteNode(struct BinaryTreeNode* root, int key){
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct BinaryTreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct BinaryTreeNode* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct BinaryTreeNode* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/*----------------------------------------------------*/
int main(int argc, char ** argv){
    // Take input from command line regarding file name
    // argv[1] === <filename.txt> file to be opened in program

    if(argc != 2){
        printf("\nINVALID ARGUMENTS");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if(!fp) {
        printf("Cannot open file. Terminating ...");
        exit(EXIT_FAILURE);
    }

    int node_data, parent_data, root_node_val;
    char left_or_right;
    int n;
    int node_to_delete;

    fscanf(fp, "%d", &n);
    --n;
    fscanf(fp, "%d", &root_node_val);

    struct BinaryTreeNode* root = get_new_node(root_node_val);

    while(n--){
        fscanf(fp,"%d %d %c", &node_data, &parent_data, &left_or_right);
        root = insert_node(root, node_data, parent_data, left_or_right);
    }

    // REad the node to delete
    fscanf(fp, "%d", &node_to_delete);

    // Print original tree
    printf("\nThe tree is : \n");
    print_tree(root, 0);
    printf("\n");

    // Node to delete
    printf("\nDELETING NODE %d", node_to_delete);

    // delete
    root = deleteNode(root, node_to_delete);

    // Print the tree again
    printf("\nThe tree after DELETION is : \n");
    print_tree(root, 0);
    printf("\n");
    return 0;
}