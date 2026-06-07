#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

// Create a new node
CNode* createNode(int data);

// Insertion functions
CNode* insertAtBeginning(CNode* head, int data);
CNode* insertAtEnd(CNode* head, int data);
CNode* insertAtPosition(CNode* head, int data, int position);

// Deletion functions
CNode* deleteFromBeginning(CNode* head);
CNode* deleteFromEnd(CNode* head);
CNode* deleteAtPosition(CNode* head, int position);

// View function
int peek(CNode* head);

// Traversal function
void traverse(CNode* head);

// Creation from array
CNode* createListFromArray(int arr[], int size);

#endif // CIRCULAR_LINKED_LIST_H
