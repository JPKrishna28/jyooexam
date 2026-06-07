#ifndef ADVANCED_TREES_H
#define ADVANCED_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ========== BINARY SEARCH TREE ==========
typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* createBSTNode(int data);
BSTNode* insertBST(BSTNode* root, int data);
void inorderBST(BSTNode* root);
BSTNode* deleteBST(BSTNode* root, int data);
BSTNode* searchBST(BSTNode* root, int data);

// ========== AVL TREE ==========
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

int getHeight(AVLNode* node);
int getBalance(AVLNode* node);
AVLNode* createAVLNode(int data);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
AVLNode* insertAVL(AVLNode* root, int data);
void inorderAVL(AVLNode* root);
AVLNode* deleteAVL(AVLNode* root, int data);

// ========== RED-BLACK TREE ==========
typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int data;
    Color color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
} RBNode;

RBNode* createRBNode(int data);
RBNode* insertRB(RBNode* root, int data);
void inorderRB(RBNode* root);

#endif // ADVANCED_TREES_H
