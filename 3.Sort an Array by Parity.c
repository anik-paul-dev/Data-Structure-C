#include <stdio.h>

void sortByParity(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        while (arr[right] % 2 != 0 && left < right) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d non-negative integers: ", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortByParity(arr, n);

    printf("Sorted array by parity: ");
    printArray(arr, n);

    return 0;
}
