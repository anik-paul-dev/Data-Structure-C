#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct {
    int data;
    int next;
} Node;

#define MAX_NODES 100

Node nodes[MAX_NODES];
int head = -1;
int freeList = 0;

// Initialize the array-based linked list
void initialize() {
    int i;
    for (i = 0; i < MAX_NODES - 1; i++) {
        nodes[i].next = i + 1;
    }
    nodes[MAX_NODES - 1].next = -1;
}

// Allocate a node from the free list
int allocate_node() {
    if (freeList == -1) {
        printf("No free nodes available.\n");
        exit(1);
    }
    int newNode = freeList;
    freeList = nodes[freeList].next;
    return newNode;
}

// Free a node back to the free list
void free_node(int node) {
    nodes[node].next = freeList;
    freeList = node;
}

// Function to insert a node at the end of the list
void insert_at_end(int data) {
    int newNode = allocate_node();
    nodes[newNode].data = data;
    nodes[newNode].next = -1;

    if (head == -1) {
        head = newNode;
        return;
    }

    int temp = head;
    while (nodes[temp].next != -1) {
        temp = nodes[temp].next;
    }
    nodes[temp].next = newNode;
}

// Function to delete a node with a specific value
void delete_node(int value) {
    int temp = head;
    int prev = -1;

    // If the head node itself holds the key to be deleted
    if (temp != -1 && nodes[temp].data == value) {
        head = nodes[temp].next;
        free_node(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != -1 && nodes[temp].data != value) {
        prev = temp;
        temp = nodes[temp].next;
    }

    // If key was not present in the linked list
    if (temp == -1) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    nodes[prev].next = nodes[temp].next;
    free_node(temp);
}

// Function to display the linked list
void display() {
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", nodes[temp].data);
        temp = nodes[temp].next;
    }
    printf("NULL\n");
}

int main() {
    initialize();
    int choice, data;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete node by value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                delete_node(data);
                break;
            case 3:
                printf("Linked List: ");
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
