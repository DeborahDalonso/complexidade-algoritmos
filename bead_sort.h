#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BEAD(i, j) beads[i * max + j]

// function to perform the above algorithm
void beadsort(int *a, int len) {
    // Find the maximum element
    int max = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }


    // Allocate memory for the beads array (histogram)
    int *beads = (int *)calloc(max + 1, sizeof(int));
    if (beads == NULL) {
        printf("Memory allocation failed!\n");
        return; // Exit the function
    }


    // mark the beads
    for (int i = 0; i < len; i++) {
        beads[a[i]]++;
    }


    // Put sorted values in array using beads
    int index = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < beads[i]; j++) {
            a[index++] = i;
        }
    }


    // Free the allocated memory
    free(beads);
}