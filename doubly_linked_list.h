#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// Create a new node
DNode* createNode(int data);

// Insertion functions
DNode* insertAtBeginning(DNode* head, int data);
DNode* insertAtEnd(DNode* head, int data);
DNode* insertAtPosition(DNode* head, int data, int position);

// Deletion functions
DNode* deleteFromBeginning(DNode* head);
DNode* deleteFromEnd(DNode* head);
DNode* deleteAtPosition(DNode* head, int position);

// View function
int peek(DNode* head);

// Traversal functions
void traverseForward(DNode* head);
void traverseBackward(DNode* head);

// Creation from array
DNode* createListFromArray(int arr[], int size);

#endif // DOUBLY_LINKED_LIST_H
