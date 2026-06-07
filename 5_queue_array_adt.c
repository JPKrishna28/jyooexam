#include <stdio.h>
#include <stdlib.h>

// Queue using Array
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} QueueArray;

// Queue using ADT (Linked List)
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} QueueADT;

// ========== QUEUE USING ARRAY ==========

QueueArray* createQueueArray() {
    QueueArray* queue = (QueueArray*)malloc(sizeof(QueueArray));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueueArray(QueueArray* queue, int data) {
    if (queue->rear >= MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (queue->front == -1) queue->front = 0;
    queue->arr[++queue->rear] = data;
    printf("Enqueued %d\n", data);
}

int dequeueArray(QueueArray* queue) {
    if (queue->front > queue->rear || queue->front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    printf("Dequeued %d\n", queue->arr[queue->front]);
    return queue->arr[queue->front++];
}

int peekQueueArray(QueueArray* queue) {
    if (queue->front > queue->rear || queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void displayQueueArray(QueueArray* queue) {
    if (queue->front > queue->rear || queue->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (Array): ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// ========== QUEUE USING ADT ==========

QueueADT* createQueueADT() {
    QueueADT* queue = (QueueADT*)malloc(sizeof(QueueADT));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueueADT(QueueADT* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Enqueued %d\n", data);
}

int dequeueADT(QueueADT* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    printf("Dequeued %d\n", data);
    free(temp);
    return data;
}

int peekQueueADT(QueueADT* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

void displayQueueADT(QueueADT* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (ADT): ");
    QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Demo function
void demo() {
    printf("=== QUEUE OPERATIONS ===\n\n");
    
    // Queue using Array
    printf("1. QUEUE USING ARRAY:\n");
    QueueArray* queueArr = createQueueArray();
    
    enqueueArray(queueArr, 10);
    enqueueArray(queueArr, 20);
    enqueueArray(queueArr, 30);
    displayQueueArray(queueArr);
    printf("Front: %d\n", peekQueueArray(queueArr));
    
    dequeueArray(queueArr);
    dequeueArray(queueArr);
    displayQueueArray(queueArr);
    printf("\n");
    
    // Queue using ADT
    printf("2. QUEUE USING ADT (LINKED LIST):\n");
    QueueADT* queueADT = createQueueADT();
    
    enqueueADT(queueADT, 100);
    enqueueADT(queueADT, 200);
    enqueueADT(queueADT, 300);
    displayQueueADT(queueADT);
    printf("Front: %d\n", peekQueueADT(queueADT));
    
    dequeueADT(queueADT);
    dequeueADT(queueADT);
    displayQueueADT(queueADT);
}

int main() {
    demo();
    return 0;
}
