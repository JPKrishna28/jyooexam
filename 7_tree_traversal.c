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

// Create a new tree node
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ========== RECURSIVE TRAVERSALS ==========

// In-order Traversal (Left-Root-Right)
void inorderRecursive(TreeNode* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

// Pre-order Traversal (Root-Left-Right)
void preorderRecursive(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// Post-order Traversal (Left-Right-Root)
void postorderRecursive(TreeNode* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

// ========== NON-RECURSIVE TRAVERSALS (USING STACK) ==========

typedef struct {
    TreeNode* arr[100];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, TreeNode* node) {
    if (stack->top < 99) {
        stack->arr[++stack->top] = node;
    }
}

TreeNode* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return NULL;
}

TreeNode* peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top];
    }
    return NULL;
}

// In-order Traversal (Non-recursive)
void inorderNonRecursive(TreeNode* root) {
    Stack* stack = createStack();
    TreeNode* current = root;
    
    while (current != NULL || stack->top >= 0) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Pre-order Traversal (Non-recursive)
void preorderNonRecursive(TreeNode* root) {
    if (root == NULL) return;
    
    Stack* stack = createStack();
    push(stack, root);
    
    while (stack->top >= 0) {
        TreeNode* node = pop(stack);
        printf("%d ", node->data);
        
        if (node->right != NULL) push(stack, node->right);
        if (node->left != NULL) push(stack, node->left);
    }
}

// Post-order Traversal (Non-recursive)
void postorderNonRecursive(TreeNode* root) {
    if (root == NULL) return;
    
    Stack* stack = createStack();
    TreeNode* lastVisited = NULL;
    TreeNode* current = root;
    
    while (stack->top >= 0 || current != NULL) {
        if (current != NULL) {
            push(stack, current);
            current = current->left;
        } else {
            TreeNode* peekNode = peek(stack);
            if (peekNode->right != NULL && peekNode->right != lastVisited) {
                current = peekNode->right;
            } else {
                printf("%d ", peekNode->data);
                lastVisited = pop(stack);
            }
        }
    }
}

// ========== LEVEL ORDER TRAVERSAL ==========
typedef struct {
    TreeNode* arr[100];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, TreeNode* node) {
    if (q->rear < 99) {
        q->arr[++q->rear] = node;
    }
}

TreeNode* dequeue(Queue* q) {
    if (q->front <= q->rear) {
        return q->arr[q->front++];
    }
    return NULL;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue* q = createQueue();
    enqueue(q, root);
    
    while (q->front <= q->rear) {
        TreeNode* current = dequeue(q);
        printf("%d ", current->data);
        
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
}

// Demo function
void demo() {
    printf("=== TREE TRAVERSAL METHODS ===\n\n");
    
    // Create a sample tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Tree Structure:\n");
    printf("        1\n");
    printf("       / \\\n");
    printf("      2   3\n");
    printf("     / \\ / \\\n");
    printf("    4  5 6  7\n\n");
    
    printf("RECURSIVE TRAVERSALS:\n");
    
    printf("1. In-order (Left-Root-Right): ");
    inorderRecursive(root);
    printf("\n");
    
    printf("2. Pre-order (Root-Left-Right): ");
    preorderRecursive(root);
    printf("\n");
    
    printf("3. Post-order (Left-Right-Root): ");
    postorderRecursive(root);
    printf("\n\n");
    
    printf("NON-RECURSIVE TRAVERSALS:\n");
    
    printf("4. In-order (Non-recursive): ");
    inorderNonRecursive(root);
    printf("\n");
    
    printf("5. Pre-order (Non-recursive): ");
    preorderNonRecursive(root);
    printf("\n");
    
    printf("6. Post-order (Non-recursive): ");
    postorderNonRecursive(root);
    printf("\n\n");
    
    printf("7. Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");
}

int main() {
    demo();
    return 0;
}
