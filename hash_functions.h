#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TABLE_SIZE 100

// ========== HASH FUNCTIONS ==========
int divisionMethod(int key, int tableSize);
int multiplicationMethod(int key, int tableSize);
int midSquareMethod(int key, int tableSize);
int foldingMethod(int key, int tableSize);
int squaringMethod(int key, int tableSize);
int digitExtractionMethod(int key, int tableSize);

// ========== COLLISION RESOLUTION ==========
int linearProbing(int key, int tableSize, int attempt);
int quadraticProbing(int key, int tableSize, int attempt);
int doubleHashing(int key, int tableSize, int attempt);

// ========== HASH TABLE OPERATIONS ==========
typedef struct {
    int key;
    int value;
    int occupied;
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
    int size;
} HashTable;

HashTable* createHashTable();
void insert(HashTable* ht, int key, int value);
int search(HashTable* ht, int key);
void delete(HashTable* ht, int key);
void displayHashTable(HashTable* ht);

#endif // HASH_FUNCTIONS_H
