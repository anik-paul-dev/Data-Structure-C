#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {57, 88, 12, 97, 34, 61, 45, 23, 55, 70, 39, 46, 94};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    bubbleSort(arr, size);

    printf("Sorted Array:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    int position = binarySearch(arr, size, key);

    if (position != -1)
        printf("Element found at position %d.\n", position + 1);
    else
        printf("Element not found in the array.\n");

    return 0;
}
