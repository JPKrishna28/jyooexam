#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TABLE_SIZE 100

// ========== DIVISION METHOD ==========
int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

// ========== MULTIPLICATION METHOD ==========
int multiplicationMethod(int key, int tableSize) {
    double A = 0.618033988; // Golden ratio - 1
    double value = (key * A);
    return (int)((value - (int)value) * tableSize);
}

// ========== MID-SQUARE METHOD ==========
int midSquareMethod(int key, int tableSize) {
    long long squared = (long long)key * key;
    int numDigits = 0;
    long long temp = squared;
    
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }
    
    // Extract middle digits
    int start = numDigits / 4;
    int count = numDigits / 2;
    
    temp = squared;
    for (int i = 0; i < start; i++) {
        temp /= 10;
    }
    
    int result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + (temp % 10);
        temp /= 10;
    }
    
    return result % tableSize;
}

// ========== FOLDING METHOD ==========
int foldingMethod(int key, int tableSize) {
    int sum = 0;
    int tempKey = key;
    
    // Sum the parts of the key
    while (tempKey > 0) {
        sum += tempKey % 100;
        tempKey /= 100;
    }
    
    return sum % tableSize;
}

// ========== HASH TABLE IMPLEMENTATION ==========
typedef struct HashEntry {
    int key;
    int value;
    int used;
} HashEntry;

typedef struct {
    HashEntry entries[TABLE_SIZE];
    int size;
} HashTable;

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = TABLE_SIZE;
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i].used = 0;
        table->entries[i].key = -1;
        table->entries[i].value = -1;
    }
    return table;
}

// ========== LINEAR PROBING FOR COLLISION HANDLING ==========
void insertWithLinearProbing(HashTable* table, int key, int value, 
                             int (*hashFunc)(int, int)) {
    int index = hashFunc(key, table->size);
    int originalIndex = index;
    int count = 0;
    
    while (table->entries[index].used && count < table->size) {
        index = (index + 1) % table->size;
        count++;
    }
    
    if (count == table->size) {
        printf("Hash table is full!\n");
        return;
    }
    
    table->entries[index].key = key;
    table->entries[index].value = value;
    table->entries[index].used = 1;
}

int searchWithLinearProbing(HashTable* table, int key, int (*hashFunc)(int, int)) {
    int index = hashFunc(key, table->size);
    int originalIndex = index;
    
    while (table->entries[index].used) {
        if (table->entries[index].key == key) {
            return table->entries[index].value;
        }
        index = (index + 1) % table->size;
        if (index == originalIndex) break;
    }
    
    return -1; // Not found
}

void displayHashTable(HashTable* table) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < table->size; i++) {
        if (table->entries[i].used) {
            printf("Index %d: Key=%d, Value=%d\n", i, table->entries[i].key, 
                   table->entries[i].value);
        }
    }
}

// Demo function
void demo() {
    printf("=== HASH FUNCTIONS ===\n\n");
    
    int keys[] = {23, 45, 56, 12, 34, 78, 90};
    int numKeys = 7;
    
    printf("Keys to insert: ");
    for (int i = 0; i < numKeys; i++) {
        printf("%d ", keys[i]);
    }
    printf("\n\n");
    
    // Division Method
    printf("1. DIVISION METHOD (h(k) = k mod m):\n");
    printf("Hash values: ");
    for (int i = 0; i < numKeys; i++) {
        int hash = divisionMethod(keys[i], TABLE_SIZE);
        printf("%d ", hash);
    }
    printf("\n\n");
    
    // Multiplication Method
    printf("2. MULTIPLICATION METHOD (h(k) = floor(m * frac(k*A))):\n");
    printf("A = 0.618033988\n");
    printf("Hash values: ");
    for (int i = 0; i < numKeys; i++) {
        int hash = multiplicationMethod(keys[i], TABLE_SIZE);
        printf("%d ", hash);
    }
    printf("\n\n");
    
    // Mid-Square Method
    printf("3. MID-SQUARE METHOD:\n");
    printf("Extract middle digits of k^2\n");
    printf("Hash values: ");
    for (int i = 0; i < numKeys; i++) {
        int hash = midSquareMethod(keys[i], TABLE_SIZE);
        printf("%d ", hash);
    }
    printf("\n\n");
    
    // Folding Method
    printf("4. FOLDING METHOD:\n");
    printf("Divide key into parts and sum them\n");
    printf("Hash values: ");
    for (int i = 0; i < numKeys; i++) {
        int hash = foldingMethod(keys[i], TABLE_SIZE);
        printf("%d ", hash);
    }
    printf("\n\n");
    
    // Hash Table with collision handling
    printf("HASH TABLE IMPLEMENTATION (Using Division Method + Linear Probing):\n");
    HashTable* table = createHashTable();
    
    for (int i = 0; i < numKeys; i++) {
        insertWithLinearProbing(table, keys[i], i * 10, divisionMethod);
        printf("Inserted key %d\n", keys[i]);
    }
    
    printf("\n");
    displayHashTable(table);
    
    printf("\nSearching for key 45: Value = %d\n", 
           searchWithLinearProbing(table, 45, divisionMethod));
    printf("Searching for key 99: Value = %d\n", 
           searchWithLinearProbing(table, 99, divisionMethod));
}

int main() {
    demo();
    return 0;
}
