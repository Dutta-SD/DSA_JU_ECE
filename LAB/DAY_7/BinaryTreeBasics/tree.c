// To check if tree is strictly binary or not
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

// This function tests if a binary tree is a full binary tree.
int is_strictly_binary_tree (struct BinaryTreeNode* root){
    // If empty tree
    if (root == NULL)
        return 1;
  
    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;
  
    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->left) && (root->right))
        return (is_strictly_binary_tree(root->left) && is_strictly_binary_tree(root->right));
  
    // We reach here when none of the above if conditions work
    return 0;
}

// Returns depth of leftmost leaf.
int findADepth(struct BinaryTreeNode *node){
   int d = 0;
   while (node != NULL){
      d++;
      node = node->left;
   }
   return d;
}
  
/* This function tests if a binary tree is perfect
   or not. It basically checks for two things :
   1) All leaves are at same level
   2) All internal nodes have two children */
int isComplRec(struct BinaryTreeNode* root, int d, int level){
    // An empty tree is perfect
    if (root == NULL)
        return 1;
  
    // If leaf node, then its depth must be same as
    // depth of all other leaves.
    if (root->left == NULL && root->right == NULL)
        return (d == level+1);
  
    // If internal node and one child is empty
    if (root->left == NULL || root->right == NULL)
        return 0;
  
    // Left and right subtrees must be perfect.
    return isComplRec(root->left, d, level+1) &&
           isComplRec(root->right, d, level+1);
}
  
// Wrapper 
int is_complete_binary_tree(struct BinaryTreeNode *root){
   int d = findADepth(root);
   return isComplRec(root, d, 0);
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

    if(is_strictly_binary_tree(root)){
        printf("\nYES !! Strictly Binary Tree !!\n");
    } else {
        printf("NO!! Not strictly binary tree\n");
    }

    if(is_complete_binary_tree(root)){
        printf("\nYES !! Complete Binary Tree !!\n");
    } else {
        printf("NO!! Not Complete binary tree\n");
    }

    return 0;
}