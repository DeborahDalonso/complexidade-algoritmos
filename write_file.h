#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

void writeFile(const char* filename, int n, const char* type, long long startTime, long long endTime, long long elapsedTime, bool printHeader) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    if (printHeader) {
        fprintf(file, "-------------------------------------------------------------------------------------------------------------------\n");
        fprintf(file, "Quantidade de itens no array: %d\n", n);
        fprintf(file, "-------------------------------------------------------------------------------------------------------------------\n");
    }

    fprintf(file, "(Array %s)\nStart Time: %lld\nEnd Time: %lld\nElapsed Time: %lld microssegundos\n\n", type, startTime, endTime, elapsedTime);

    fclose(file);
}

