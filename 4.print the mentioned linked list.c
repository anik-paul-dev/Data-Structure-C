#include <stdio.h>
#define NULL 0

void printList(char values[], int links[], int start) {
    int current = start - 1;

    // Print the linked list
    printf("Linked list values: ");
    while (current != NULL - 1) {
        printf("%c ", values[current]);
        current = links[current] - 1;
    }
    printf("\n");
}

int main() {
    char values[] = {
        'A', // Node 1
        'S', // Node 2
        'F', // Node 3
        ' ', // Node 4
        ' ', // Node 5
        'K', // Node 6
        'R', // Node 7
        ' ', // Node 8
        'W', // Node 9
        'T', // Node 10
        'Y', // Node 11
        ' ', // Node 12
        ' ', // Node 13
        'U', // Node 14
        ' ', // Node 15
        'I', // Node 16
        'P'  // Node 17
    };

    int links[] = {
        15, // Node 1
        9,  // Node 2
        NULL, // Node 3
        14, // Node 4
        NULL, // Node 5
        2,  // Node 6
        1,  // Node 7
        4,  // Node 8
        13, // Node 9
        3,  // Node 10
        7,  // Node 11
        17, // Node 12
        16, // Node 13
        12, // Node 14
        10, // Node 15
        11, // Node 16
        5   // Node 17
    };

    int start = 6; // Start index
    printList(values, links, start);
    return 0;
}
