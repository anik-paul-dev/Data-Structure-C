#include <stdio.h>
#define MAX_SIZE 20

int main() {
    int arr[MAX_SIZE] = {57, 88, 12, 97, 34, 61, 45, 23, 55, 70, 39, 46, 94};
    int size = 13;
    int i, pos, newElement;

    printf("Initial Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &newElement);

    for (i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = newElement;

    size++;

    printf("\nArray after insertion:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
