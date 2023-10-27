#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from user input
struct TreeNode* buildTree() {
    int val;
    printf("Enter data (or -1 for a null node): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL; // Indicates a null node
    }

    struct TreeNode* newNode = createNode(val);

    printf("Enter left child of %d:\n", val);
    newNode->left = buildTree();

    printf("Enter right child of %d:\n", val);
    newNode->right = buildTree();

    return newNode;
}

// Function to print the binary tree structure horizontally
void printTreeStructure(struct TreeNode* root, int level) {
    if (root != NULL) {
        // Print the right subtree
        printTreeStructure(root->right, level + 1);

        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d\n", root->val);

        // Print the left subtree
        printTreeStructure(root->left, level + 1);
    }
}

// Function to perform a preorder traversal and print the nodes
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    printf("Enter the binary tree structure:\n");
    struct TreeNode* root = buildTree();

    // Print the binary tree structure horizontally
    printf("Binary Tree Structure (from left to right):\n");
    printTreeStructure(root, 0);

    // Perform preorder traversal
    printf("Preorder Traversal: ");
    preorderTraversal(root);

    return 0;
}
