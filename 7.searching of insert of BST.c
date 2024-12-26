#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define EMPTY -1

void initializeBST(int bst[], int size) {

    int i;
    for (i = 0; i < size; i++) {
        bst[i] = EMPTY;
    }
}

void insert(int bst[], int value) {
    int index = 0;

    while (index < SIZE && bst[index] != EMPTY) {
        if (value < bst[index]) {
            index = 2 * index + 1;
        } else if (value > bst[index]) {
            index = 2 * index + 2;
        } else {
            printf("Value %d already exists in the BST.\n", value);
            return;
        }
    }

    if (index < SIZE) {
        bst[index] = value;
        printf("Value %d inserted into the BST.\n", value);
    } else {
        printf("Error: BST is full, cannot insert value %d.\n", value);
    }
}

int search(int bst[], int value) {
    int index = 0;

    while (index < SIZE && bst[index] != EMPTY) {
        if (bst[index] == value) {
            return index;
        } else if (value < bst[index]) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }

    return -1;
}

void inorderTraversal(int bst[], int index) {
    if (index >= SIZE || bst[index] == EMPTY) {
        return;
    }

    inorderTraversal(bst, 2 * index + 1);

    printf("%d ", bst[index]);

    inorderTraversal(bst, 2 * index + 2);
}

int main() {
    int bst[SIZE];
    int choice, value;

    initializeBST(bst, SIZE);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(bst, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                int result = search(bst, value);
                if (result != -1) {
                    printf("Value %d found at index %d in the BST.\n", value, result);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;

            case 3:
                printf("In-order traversal of the BST: ");
                inorderTraversal(bst, 0);
                printf("\n");
                break;

            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
