#include <stdio.h>

// Function to add K to each element in the array
void add_to_each_element(int* array, int size, int K) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] += K;
    }
}

// Function to display the array
void display_array(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, K;

    // Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int VALUES[n];

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &VALUES[i]);
    }

    // Get the value of K
    printf("Enter the value to add to each element (K): ");
    scanf("%d", &K);

    // Add K to each element
    add_to_each_element(VALUES, n, K);

    // Display the updated array
    printf("Updated array:\n");
    display_array(VALUES, n);

    return 0;
}
