#ifndef QUEUE_ARRAY_ADT_H
#define QUEUE_ARRAY_ADT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue using Array
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
QueueArray* createQueueArray();
void enqueueArray(QueueArray* queue, int data);
int dequeueArray(QueueArray* queue);
int peekQueueArray(QueueArray* queue);
int isEmptyQueueArray(QueueArray* queue);
void displayQueueArray(QueueArray* queue);

// ========== QUEUE USING ADT ==========
QueueADT* createQueueADT();
void enqueueADT(QueueADT* queue, int data);
int dequeueADT(QueueADT* queue);
int peekQueueADT(QueueADT* queue);
int isEmptyQueueADT(QueueADT* queue);
void displayQueueADT(QueueADT* queue);

#endif // QUEUE_ARRAY_ADT_H
