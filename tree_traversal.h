#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* arr[100];
    int top;
} Stack;

typedef struct {
    TreeNode* arr[100];
    int front, rear;
} Queue;

// ========== NODE CREATION ==========
TreeNode* createNode(int data);

// ========== RECURSIVE TRAVERSALS ==========
void inorderRecursive(TreeNode* root);
void preorderRecursive(TreeNode* root);
void postorderRecursive(TreeNode* root);

// ========== NON-RECURSIVE TRAVERSALS ==========
void inorderIterative(TreeNode* root);
void preorderIterative(TreeNode* root);
void postorderIterative(TreeNode* root);
void levelOrderTraversal(TreeNode* root);

// ========== UTILITY FUNCTIONS ==========
TreeNode* insertNode(TreeNode* root, int data);
void displayTree(TreeNode* root);

#endif // TREE_TRAVERSAL_H
