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

// Function to print the binary tree structure
void printTreeStructure(struct TreeNode* root, int level) {
    if (root != NULL) {
        printTreeStructure(root->right, level + 1);

        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        printf("%d\n", root->data);

        printTreeStructure(root->left, level + 1);
    }
}

int main() {
    // Create a binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the binary tree structure
    printf("Binary Tree Structure:\n");
    printTreeStructure(root, 0);

    // The output will resemble the structure of the binary tree.

    return 0;
}
