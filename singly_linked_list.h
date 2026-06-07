#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data);

// Insertion functions
Node* insertAtBeginning(Node* head, int data);
Node* insertAtEnd(Node* head, int data);
Node* insertAtPosition(Node* head, int data, int position);

// Deletion functions
Node* deleteFromBeginning(Node* head);
Node* deleteFromEnd(Node* head);
Node* deleteAtPosition(Node* head, int position);

// View function
int peek(Node* head);

// Traversal function
void traverse(Node* head);

// Creation from array
Node* createListFromArray(int arr[], int size);

#endif // SINGLY_LINKED_LIST_H
