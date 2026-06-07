#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ========== RADIX SORT ==========
int getMax(int arr[], int n);
void countingSortRadix(int arr[], int n, int exp);
void radixSort(int arr[], int n);

// ========== HEAP SORT ==========
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// ========== MERGE SORT ==========
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

// ========== QUICK SORT ==========
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// ========== BUBBLE SORT ==========
void bubbleSort(int arr[], int n);

// ========== SELECTION SORT ==========
void selectionSort(int arr[], int n);

// ========== INSERTION SORT ==========
void insertionSort(int arr[], int n);

// ========== UTILITY FUNCTIONS ==========
void printArray(int arr[], int n);
void copyArray(int src[], int dest[], int n);

#endif // SORTING_ALGORITHMS_H
