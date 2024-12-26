#include <stdio.h>

void insertionSortDescending(int arr[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int findKthLargest(int arr[], int n, int k) {
    insertionSortDescending(arr, n);

    return arr[k - 1];
}

int main() {
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        int kthLargest = findKthLargest(arr, n, k);
        printf("The %dth largest element is: %d\n", k, kthLargest);
    } else {
        printf("Invalid value of k. It should be between 1 and %d.\n", n);
    }

    return 0;
}
