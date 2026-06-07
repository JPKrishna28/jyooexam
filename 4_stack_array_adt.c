#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} StackArray;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} StackADT;

// ========== STACK USING ARRAY ==========

StackArray* createStackArray() {
    StackArray* stack = (StackArray*)malloc(sizeof(StackArray));
    stack->top = -1;
    return stack;
}

void pushArray(StackArray* stack, int data) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Pushed %d\n", data);
}

int popArray(StackArray* stack) {
    if (stack->top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    }
    printf("Popped %d\n", stack->arr[stack->top]);
    return stack->arr[stack->top--];
}

int peekArray(StackArray* stack) {
    if (stack->top < 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void displayArray(StackArray* stack) {
    if (stack->top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (Array): ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// ========== STACK USING ADT ==========

StackADT* createStackADT() {
    StackADT* stack = (StackADT*)malloc(sizeof(StackADT));
    stack->top = NULL;
    return stack;
}

void pushADT(StackADT* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d\n", data);
}

int popADT(StackADT* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    printf("Popped %d\n", data);
    free(temp);
    return data;
}

int peekADT(StackADT* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

void displayADT(StackADT* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (ADT): ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Demo function
void demo() {
    printf("=== STACK OPERATIONS ===\n\n");
    
    // Stack using Array
    printf("1. STACK USING ARRAY:\n");
    StackArray* stackArr = createStackArray();
    
    pushArray(stackArr, 10);
    pushArray(stackArr, 20);
    pushArray(stackArr, 30);
    displayArray(stackArr);
    printf("Peek: %d\n", peekArray(stackArr));
    
    popArray(stackArr);
    popArray(stackArr);
    displayArray(stackArr);
    printf("\n");
    
    // Stack using ADT
    printf("2. STACK USING ADT (LINKED LIST):\n");
    StackADT* stackADT = createStackADT();
    
    pushADT(stackADT, 100);
    pushADT(stackADT, 200);
    pushADT(stackADT, 300);
    displayADT(stackADT);
    printf("Peek: %d\n", peekADT(stackADT));
    
    popADT(stackADT);
    popADT(stackADT);
    displayADT(stackADT);
}

int main() {
    demo();
    return 0;
}
