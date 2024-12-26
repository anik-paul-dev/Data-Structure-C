#include <stdio.h>
#define MAX_SIZE 20

int main() {
    int arr[MAX_SIZE] = {57, 88, 12, 97, 34, 61, 45, 23, 55, 70, 39, 46, 94};
    int size = 13;
    int i, pos;
    printf("Initial Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return 1;
    }
    for (i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("\nArray after deletion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
