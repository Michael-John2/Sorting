#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int n = 10;
    int nums[10];

    // Fill with random numbers between 1 and 99
    for (int i = 0; i < n; i++)
        nums[i] = rand() % 99 + 1;

    int comparisons = 0, assignments = 0, swaps = 0, step = 0;

    printf("=== CUSTOM SORTING ANALYSIS ===\n\n");

    printf("Initial Array: [ ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("]\n\n--- SORTING PROGRESS ---\n\n");

    // Bubble sort with tracking
    for (int i = 0; i < n - 1; i++) {
        comparisons++;                          // while/for condition
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;                      // inner loop condition
            comparisons++;                      // if comparison

            if (nums[j] > nums[j + 1]) {
                step++;
                printf("Step %d: Comparing %d and %d, need to rearrange...\n", step, nums[j], nums[j + 1]);

                // Swap
                int temp = nums[j];             assignments++;
                nums[j] = nums[j + 1];          assignments++;
                nums[j + 1] = temp;             assignments++;
                swaps++;

                printf("Current: [ ");
                for (int k = 0; k < n; k++) printf("%d ", nums[k]);
                printf("]\n\n");
            } else {
                step++;
                printf("Step %d: Comparing %d and %d, order is correct\n", step, nums[j], nums[j + 1]);

                printf("Current: [ ");
                for (int k = 0; k < n; k++) printf("%d ", nums[k]);
                printf("]\n\n");
            }
        }
    }

    printf("Final Sorted Array: [ ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("]\n\n");

    printf("=== OPERATION STATISTICS ===\n");
    printf("Comparisons: %d\n", comparisons);
    printf("Assignments: %d\n", assignments);
    printf("Swaps:       %d\n", swaps);
    printf("Total Operations: %d\n", comparisons + assignments + swaps);

    return 0;
}
