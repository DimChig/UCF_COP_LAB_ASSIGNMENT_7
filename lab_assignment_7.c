#include <stdio.h>

int bubbleSort(int arr[], int n, int swaps_array[]) {
    int i, j, temp, total_swaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps_array[arr[j]]++;
                swaps_array[arr[j + 1]]++;
                total_swaps++;
            }
        }
    }
    return total_swaps;
}

int selectionSort(int arr[], int n, int swaps_array[]) {
    int i, j, min_idx, temp, total_swaps = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            swaps_array[arr[min_idx]]++;
            swaps_array[arr[i]]++;
            total_swaps++;
        }
    }
    return total_swaps;
}

int main() {
    int n1 = 8;
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int swaps_array1[100] = {0};

    printf("array1 (Bubble sort):\n");
    int total_swaps = bubbleSort(array1, n1, swaps_array1);
    for (int i = 0; i < n1; i++) {
        printf("%d: # of times %d is swapped\n", array1[i], swaps_array1[array1[i]]);
    }
    printf("Total # of swaps: %d\n", total_swaps);


    int n2 = 8;
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps_array2[100] = {0};

    printf("\narray2 (Selection sort):\n");
    total_swaps = selectionSort(array2, n2, swaps_array2);
    for (int i = 0; i < n2; i++) {
        printf("%d: # of times %d is swapped\n", array2[i], swaps_array2[array2[i]]);
    }
    printf("Total # of swaps: %d", total_swaps);

    return 0;
}