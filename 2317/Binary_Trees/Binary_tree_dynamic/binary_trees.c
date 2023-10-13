#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from user input
struct TreeNode* buildTree() {
    int data;
    printf("Enter root node value (or -1 to skip): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // Indicates an empty node
    }

    struct TreeNode* newNode = createNode(data);
    printf("Enter left subtree for %d:\n", data);
    newNode->left = buildTree();
    printf("Enter right subtree for %d:\n", data);
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
        printf("%d\n", root->data);

        // Print the left subtree
        printTreeStructure(root->left, level + 1);
    }
}

int main() {
    printf("Enter binary tree structure (use -1 for empty nodes):\n");
    struct TreeNode* root = buildTree();

    // Print the binary tree structure horizontally
    printf("Binary Tree Structure (from left to right):\n");
    printTreeStructure(root, 0);
    return 0;
}
