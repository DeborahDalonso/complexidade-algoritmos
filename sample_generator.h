#include <stdlib.h>
#include <time.h>

void fillAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void fillDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i - 1;
    }
}

void fillRandom(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 2);
    }
}

void fillPartiallySorted(int arr[], int n) {
    int sortedPart = n / 2;
    fillAscending(arr, sortedPart);
    fillRandom(arr + sortedPart, n - sortedPart);
}