#ifndef STACK_ARRAY_ADT_H
#define STACK_ARRAY_ADT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack using Array
typedef struct {
    int arr[MAX_SIZE];
    int top;
} StackArray;

// Stack using ADT (Linked List)
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} StackADT;

// ========== STACK USING ARRAY ==========
StackArray* createStackArray();
void pushArray(StackArray* stack, int data);
int popArray(StackArray* stack);
int peekArray(StackArray* stack);
int isEmptyArray(StackArray* stack);
void displayArray(StackArray* stack);

// ========== STACK USING ADT ==========
StackADT* createStackADT();
void pushADT(StackADT* stack, int data);
int popADT(StackADT* stack);
int peekADT(StackADT* stack);
int isEmptyADT(StackADT* stack);
void displayADT(StackADT* stack);

#endif // STACK_ARRAY_ADT_H
