#include "get_time.h"
#include "sample_generator.h"
#include "write_file.h"

typedef void (*SortFunction)(int*, int);
typedef void (*ArrayFiller)(int*, int);

void sortAndMeasureTime(void (*sortFunc)(int[], int), int arr[], int n, const char* filename, const char* type, bool printHeader) {
    long long startTime, endTime, elapsedTime;

    startTime = timeInMicroseconds();
    sortFunc(arr, n);
    endTime = timeInMicroseconds();

    elapsedTime = endTime - startTime;

    writeFile(filename, n, type, startTime, endTime, elapsedTime, printHeader);
    
    return;
}

void testSortingAlgorithm(SortFunction sortFunc, const char* filename, int* samples, int n) {
    struct {
        ArrayFiller filler;
        const char* description;
        bool printHeader;
    } tests[] = {
        {fillAscending, "Ordenado", true},
        {fillDescending, "Inversamente Ordenado", false},
        {fillRandom, "Aleatório", false},
        {fillPartiallySorted, "Parcialmente Ordenado", false},
    };
    //preencher toda vez é uma boa ideia, pois o array é modificado, e não queremos que um teste interfira no outro

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        tests[i].filler(samples, n);

        // printf("%s: \n", tests[i].description);
        // printArray(samples, n);
        // printf("\n------------------------Depois------------------------\n");
        sortAndMeasureTime(sortFunc, samples, n, filename, tests[i].description, tests[i].printHeader);
        // printArray(samples, n);
        // printf("\n--------------------------------------------------------\n");
    }
}