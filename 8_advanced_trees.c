#include "advanced_trees.h"

BSTNode* createBSTNode(int data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BSTNode* insertBST(BSTNode* root, int data) {
    if (root == NULL) return createBSTNode(data);
    
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    
    return root;
}

void inorderBST(BSTNode* root) {
    if (root == NULL) return;
    inorderBST(root->left);
    printf("%d ", root->data);
    inorderBST(root->right);
}

// ========== AVL TREE ==========
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

int getHeight(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

AVLNode* createAVLNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    
    return y;
}

AVLNode* insertAVL(AVLNode* node, int data) {
    if (node == NULL) return createAVLNode(data);
    
    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else
        return node;
    
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    
    int balance = getBalance(node);
    
    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);
    
    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);
    
    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

void inorderAVL(AVLNode* root) {
    if (root == NULL) return;
    inorderAVL(root->left);
    printf("%d ", root->data);
    inorderAVL(root->right);
}

// ========== RED-BLACK TREE (SIMPLIFIED) ==========
typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int data;
    Color color;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
} RBNode;

RBNode* createRBNode(int data) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->color = RED;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

RBNode* insertRB(RBNode* root, int data) {
    RBNode* newNode = createRBNode(data);
    
    if (root == NULL) {
        newNode->color = BLACK;
        return newNode;
    }
    
    RBNode* current = root;
    RBNode* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    newNode->parent = parent;
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    return root;
}

void inorderRB(RBNode* root) {
    if (root == NULL) return;
    inorderRB(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    inorderRB(root->right);
}

// ========== B-TREE (SIMPLIFIED - Order 3) ==========
typedef struct BTreeNode {
    int keys[3];
    struct BTreeNode* children[4];
    int keyCount;
    int isLeaf;
} BTreeNode;

BTreeNode* createBTreeNode() {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->keyCount = 0;
    node->isLeaf = 1;
    for (int i = 0; i < 4; i++) node->children[i] = NULL;
    return node;
}

// Demo function
void demo() {
    printf("=== ADVANCED TREE STRUCTURES ===\n\n");
    
    printf("1. BINARY SEARCH TREE:\n");
    BSTNode* bst = NULL;
    int bst_vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        bst = insertBST(bst, bst_vals[i]);
    }
    printf("BST In-order: ");
    inorderBST(bst);
    printf("\n\n");
    
    printf("2. AVL TREE:\n");
    AVLNode* avl = NULL;
    for (int i = 0; i < 7; i++) {
        avl = insertAVL(avl, bst_vals[i]);
    }
    printf("AVL In-order: ");
    inorderAVL(avl);
    printf("\n\n");
    
    printf("3. RED-BLACK TREE:\n");
    RBNode* rb = NULL;
    for (int i = 0; i < 7; i++) {
        rb = insertRB(rb, bst_vals[i]);
    }
    printf("RB In-order: ");
    inorderRB(rb);
    printf("\n\n");
    
    printf("4. B-TREE & B+ TREE (Simplified):\n");
    printf("B-Tree and B+ Tree are used for disk-based indexing\n");
    printf("B-Tree of order m can have m-1 keys and m children\n");
    printf("B+ Tree stores all data in leaf nodes\n");
}

int main() {
    demo();
    return 0;
}
