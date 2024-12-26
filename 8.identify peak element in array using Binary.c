#include <stdio.h>

int findPeakElement(int arr[], int size) {
    int low = 0, high = size - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1]) high = mid;  // Peak is in the left half
        else low = mid + 1;                      // Peak is in the right half
    }
    return low;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements: ", size);

    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Peak element found at index: %d\n", findPeakElement(arr, size));

    return 0;
}
