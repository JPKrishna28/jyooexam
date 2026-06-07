#include "sorting_algorithms.h"

// ========== RADIX SORT ==========
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSortRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortRadix(arr, n, exp);
    }
}

// ========== HEAP SORT ==========
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// ========== SHELL SORT ==========
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ========== TREE SORT ==========
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertBST(TreeNode* root, int data) {
    if (root == NULL) return createTreeNode(data);
    
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    
    return root;
}

void inorderTraversal(TreeNode* root, int arr[], int* index) {
    if (root == NULL) return;
    
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorderTraversal(root->right, arr, index);
}

void treeSort(int arr[], int n) {
    TreeNode* root = NULL;
    
    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }
    
    int index = 0;
    inorderTraversal(root, arr, &index);
}

// ========== UTILITY ==========
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Demo function
void demo() {
    printf("=== SORTING ALGORITHMS ===\n\n");
    
    int arr1[] = {170, 45, 75, 90, 2, 8, 200, 50};
    int arr2[] = {170, 45, 75, 90, 2, 8, 200, 50};
    int arr3[] = {170, 45, 75, 90, 2, 8, 200, 50};
    int arr4[] = {170, 45, 75, 90, 2, 8, 200, 50};
    int n = 8;
    
    printf("Original Array: ");
    printArray(arr1, n);
    printf("\n");
    
    printf("1. RADIX SORT:\n");
    radixSort(arr1, n);
    printf("Sorted: ");
    printArray(arr1, n);
    printf("\n");
    
    printf("2. HEAP SORT:\n");
    heapSort(arr2, n);
    printf("Sorted: ");
    printArray(arr2, n);
    printf("\n");
    
    printf("3. SHELL SORT:\n");
    shellSort(arr3, n);
    printf("Sorted: ");
    printArray(arr3, n);
    printf("\n");
    
    printf("4. TREE SORT:\n");
    treeSort(arr4, n);
    printf("Sorted: ");
    printArray(arr4, n);
}

int main() {
    demo();
    return 0;
}
