#include <stdio.h>

int findPosition(int arr[], int size, int target, int findFirst) {
    int low = 0, high = size - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            if (findFirst) high = mid - 1; // Search left half for the first position
            else low = mid + 1;            // Search right half for the last position
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted elements: ", size);

    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int first = findPosition(arr, size, target, 1);
    int last = findPosition(arr, size, target, 0);
    printf("First and Last Position: [%d, %d]\n", first, last);

    return 0;
}
