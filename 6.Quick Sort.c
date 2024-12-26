#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


void printArray(int array[], int size) {
    int i;
    for (i= 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter elements: ");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Unsorted array: ");
    printArray(array, n);

    quickSort(array, 0, n - 1);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
