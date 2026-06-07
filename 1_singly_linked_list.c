#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Insert at specific position
Node* insertAtPosition(Node* head, int data, int position) {
    if (position == 0) return insertAtBeginning(head, data);
    
    Node* newNode = createNode(data);
    Node* current = head;
    
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Delete from beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Delete at specific position
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) return NULL;
    if (position == 0) return deleteFromBeginning(head);
    
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Traversal - display all elements
void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Creation - create list from array
Node* createListFromArray(int arr[], int size) {
    if (size == 0) return NULL;
    Node* head = createNode(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Demo function
void demo() {
    printf("=== SINGLY LINKED LIST OPERATIONS ===\n\n");
    
    // Creation
    printf("1. CREATION:\n");
    int arr[] = {10, 20, 30, 40};
    Node* head = createListFromArray(arr, 4);
    traverse(head);
    printf("\n");
    
    // Insertion
    printf("2. INSERTION:\n");
    printf("Insert 5 at beginning: ");
    head = insertAtBeginning(head, 5);
    traverse(head);
    
    printf("Insert 50 at end: ");
    head = insertAtEnd(head, 50);
    traverse(head);
    
    printf("Insert 25 at position 3: ");
    head = insertAtPosition(head, 25, 3);
    traverse(head);
    printf("\n");
    
    // Deletion
    printf("3. DELETION:\n");
    printf("Delete from beginning: ");
    head = deleteFromBeginning(head);
    traverse(head);
    
    printf("Delete from end: ");
    head = deleteFromEnd(head);
    traverse(head);
    
    printf("Delete at position 2: ");
    head = deleteAtPosition(head, 2);
    traverse(head);
    printf("\n");
    
    // Traversal
    printf("4. TRAVERSAL:\n");
    traverse(head);
}

int main() {
    demo();
    return 0;
}
