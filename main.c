#include "bed_sort.h"
#include "comb_sort.h"
#include "intro_sort.h"
#include "testing_codes.h"   

int main() {
    int sizes[] = {1000, 10000, 50000, 100000, 500000, 1000000};

    for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int totalSamples = sizes[i];
        int samples[totalSamples];
        int subarray = sizeof(samples) / sizeof(int);

        testSortingAlgorithm(beadsort, "bead_sort.txt", samples, totalSamples);
        testSortingAlgorithm(combsort, "comb_sort.txt", samples, totalSamples);
        testSortingAlgorithm(introsort, "intro_sort.txt", samples, subarray);
    }
    
    return 0;
}
