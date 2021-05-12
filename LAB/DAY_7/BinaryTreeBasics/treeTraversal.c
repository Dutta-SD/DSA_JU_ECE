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
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct BinaryTreeNode* node){
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%d ", node->data);
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct BinaryTreeNode* node){
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct BinaryTreeNode* node){
    if (node == NULL)
        return;
 
    /* first print data of node */
    printf("%d ", node->data);
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}
// Driver Code
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

    fscanf(fp, "%d", &n);
    --n;
    fscanf(fp, "%d", &root_node_val);

    struct BinaryTreeNode* root = get_new_node(root_node_val);

    while(n--){
        fscanf(fp,"%d %d %c", &node_data, &parent_data, &left_or_right);
        root = insert_node(root, node_data, parent_data, left_or_right);
    }

    printf("\nThe tree is : \n");
    print_tree(root, 0);
    printf("\n");

    // Post Order
    printf("\nPOSTORDER TRAVERSAL : \n");
    printPostorder(root);
    printf("\n");

    // In Order
    printf("\nINORDER TRAVERSAL : \n");
    printInorder(root);
    printf("\n");


    // Preorder Order
    printf("\nPREORDER TRAVERSAL : \n");
    printPreorder(root);
    printf("\n");

    return 0;
}