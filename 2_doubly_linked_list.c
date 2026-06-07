#include "doubly_linked_list.h"

// Create a new node
DNode* createNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at beginning
DNode* insertAtBeginning(DNode* head, int data) {
    DNode* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

// Insert at end
DNode* insertAtEnd(DNode* head, int data) {
    DNode* newNode = createNode(data);
    if (head == NULL) return newNode;
    
    DNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Insert at position
DNode* insertAtPosition(DNode* head, int data, int position) {
    if (position == 0) return insertAtBeginning(head, data);
    
    DNode* newNode = createNode(data);
    DNode* current = head;
    
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    return head;
}

// Delete from beginning
DNode* deleteFromBeginning(DNode* head) {
    if (head == NULL) return NULL;
    DNode* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}

// Delete from end
DNode* deleteFromEnd(DNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    DNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

// Delete at position
DNode* deleteAtPosition(DNode* head, int position) {
    if (head == NULL) return NULL;
    if (position == 0) return deleteFromBeginning(head);
    
    DNode* current = head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    
    free(current);
    return head;
}

// Peek - view first element
int peek(DNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    return head->data;
}

// Forward traversal
void traverseForward(DNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Forward: NULL <- ");
    DNode* current = head;
    while (current != NULL) {
        printf(" %d <-> ", current->data);
        current = current->next;
    }
    printf(" NULL\n");
}

// Backward traversal
void traverseBackward(DNode* head) {
    if (head == NULL) return;
    
    DNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    printf("Backward: NULL <- ");
    while (current != NULL) {
        printf(" %d <-> ", current->data);
        current = current->prev;
    }
    printf(" NULL\n");
}

// Create list from array
DNode* createListFromArray(int arr[], int size) {
    if (size == 0) return NULL;
    DNode* head = createNode(arr[0]);
    DNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current->next->prev = current;
        current = current->next;
    }
    return head;
}

// Demo function
void demo() {
    printf("=== DOUBLY LINKED LIST OPERATIONS ===\n\n");
    
    // Creation
    printf("1. CREATION:\n");
    int arr[] = {15, 25, 35, 45};
    DNode* head = createListFromArray(arr, 4);
    traverseForward(head);
    traverseBackward(head);
    printf("\n");
    
    // Insertion
    printf("2. INSERTION:\n");
    printf("Insert 5 at beginning: ");
    head = insertAtBeginning(head, 5);
    traverseForward(head);
    
    printf("Insert 55 at end: ");
    head = insertAtEnd(head, 55);
    traverseForward(head);
    
    printf("Insert 30 at position 3: ");
    head = insertAtPosition(head, 30, 3);
    traverseForward(head);
    printf("\n");
    
    // Deletion
    printf("3. DELETION:\n");
    printf("Delete from beginning: ");
    head = deleteFromBeginning(head);
    traverseForward(head);
    
    printf("Delete from end: ");
    head = deleteFromEnd(head);
    traverseForward(head);
    
    
    // Peek
    printf("\n5. PEEK:\n");
    int firstElement = peek(head);
    if (firstElement != -1) {
        printf("First element (peek): %d\n", firstElement);
    }
    printf("Delete at position 2: ");
    head = deleteAtPosition(head, 2);
    traverseForward(head);
    printf("\n");
    
    // Traversal
    printf("4. TRAVERSAL:\n");
    traverseForward(head);
    traverseBackward(head);
}

int main() {
    demo();
    return 0;
}
