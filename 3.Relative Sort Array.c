#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void relativeSort(int arr1[], int n1, int arr2[], int n2) {
    int count[1001] = {0};
    int sortedIndex = 0;

    int i;
    for (i = 0; i < n1; i++) {
        count[arr1[i]]++;
    }

    for (i = 0; i < n2; i++) {
        while (count[arr2[i]] > 0) {
            arr1[sortedIndex++] = arr2[i];
            count[arr2[i]]--;
        }
    }
    int remaining[n1];
    int remainingIndex = 0;

    for (i = 0; i < 1001; i++) {
        while (count[i] > 0) {
            remaining[remainingIndex++] = i;
            count[i]--;
        }
    }

    qsort(remaining, remainingIndex, sizeof(int), compare);

    for (i = 0; i < remainingIndex; i++) {
        arr1[sortedIndex++] = remaining[i];
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
    int n1, n2;

    printf("Enter the number of elements in arr1: ");
    scanf("%d", &n1);
    int arr1[n1];

    printf("Enter %d elements of arr1: ", n1);
    int i;
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in arr2: ");
    scanf("%d", &n2);
    int arr2[n2];

    printf("Enter %d elements of arr2: ", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    relativeSort(arr1, n1, arr2, n2);

    printf("Sorted arr1: ");
    printArray(arr1, n1);

    return 0;
}
