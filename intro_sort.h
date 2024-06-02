#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int A[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}


void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void heapsort(int A[], int n) {
    // Implementação simplificada de heapsort.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void introsortUtil(int A[], int n, int maxdepth) {
    if (n < 16) {
        insertionsort(A, n);
    } else if (maxdepth == 0) {
        heapsort(A, n);
    } else {
        int p = partition(A, 0, n - 1);
        introsortUtil(A, p, maxdepth - 1);
        introsortUtil(A + p + 1, n - p - 1, maxdepth - 1);
    }
}

void introsort(int A[], int n) {
    int maxdepth = (int)(log(n) / log(2)) * 2;
    introsortUtil(A, n, maxdepth);
}