#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

// Create a new node
CNode* createNode(int data) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
CNode* insertAtBeginning(CNode* head, int data) {
    CNode* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    CNode* current = head;
    while (current->next != head) {
        current = current->next;
    }
    newNode->next = head;
    current->next = newNode;
    return newNode;
}

// Insert at end
CNode* insertAtEnd(CNode* head, int data) {
    CNode* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    CNode* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

// Insert at position
CNode* insertAtPosition(CNode* head, int data, int position) {
    if (position == 0) return insertAtBeginning(head, data);
    
    CNode* newNode = createNode(data);
    CNode* current = head;
    
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Position out of range!\n");
            free(newNode);
            return head;
        }
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Delete from beginning
CNode* deleteFromBeginning(CNode* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    
    CNode* current = head;
    while (current->next != head) {
        current = current->next;
    }
    
    CNode* temp = head;
    current->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
CNode* deleteFromEnd(CNode* head) {
    if (head == NULL) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    
    CNode* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    
    free(current->next);
    current->next = head;
    return head;
}

// Delete at position
CNode* deleteAtPosition(CNode* head, int position) {
    if (head == NULL) return NULL;
    if (position == 0) return deleteFromBeginning(head);
    
    CNode* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current->next == head) {
            printf("Position out of range!\n");
            return head;
        }
    }
    
    CNode* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Peek - view first element
int peek(CNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    return head->data;
}

// Traversal
void traverse(CNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List: ");
    CNode* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to %d)\n", head->data);
}

// Create list from array
CNode* createListFromArray(int arr[], int size) {
    if (size == 0) return NULL;
    CNode* head = createNode(arr[0]);
    CNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    current->next = head;
    return head;
}

// Demo function
void demo() {
    printf("=== CIRCULAR LINKED LIST OPERATIONS ===\n\n");
    
    // Creation
    printf("1. CREATION:\n");
    int arr[] = {12, 22, 32, 42};
    CNode* head = createListFromArray(arr, 4);
    traverse(head);
    printf("\n");
    
    // Insertion
    printf("2. INSERTION:\n");
    printf("Insert 2 at beginning: ");
    head = insertAtBeginning(head, 2);
    traverse(head);
    
    printf("Insert 52 at end: ");
    head = insertAtEnd(head, 52);
    traverse(head);
    
    printf("Insert 27 at position 3: ");
    head = insertAtPosition(head, 27, 3);
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
    
    // Peek
    printf("\n5. PEEK:\n");
    int firstElement = peek(head);
    if (firstElement != -1) {
        printf("First element (peek): %d\n", firstElement);
    }
}

int main() {
    demo();
    return 0;
}
