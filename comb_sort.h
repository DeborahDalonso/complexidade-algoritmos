#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void combsort(int arr[], int n) {
    int gap = n;
    int swaps = 1;
    int i;

    while (gap > 1 || swaps == 1) {
        gap = gap / 1.25;
        if (gap < 1) gap = 1;

        swaps = 0;

        for (i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps = 1;
            }
        }
    }
}

