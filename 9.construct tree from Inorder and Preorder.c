#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search a value in the inorder array
int search(char inorder[], int start, int end, char value) {

    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(char inorder[], char preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Pick the current node from Preorder traversal using preorderIndex
    // and increment preorderIndex
    char current = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct Node* node = newNode(current);

    // If this node has no children, return
    if (inorderStart == inorderEnd)
        return node;

    // Else find the index of this node in Inorder traversal
    int inorderIndex = search(inorder, inorderStart, inorderEnd, current);

    // Recursively build the left and right subtrees
    node->left = buildTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    node->right = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return node;
}

// Function to print inorder traversal of the tree
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // First recur on left child
    printInorder(node->left);

    // Then print the data of node
    printf("%c ", node->data);

    // Now recur on right child
    printInorder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    char inorder[n], preorder[n];

    // User inputs for inorder and preorder traversals
    printf("Enter the inorder traversal: ");

    int i;
    for (i = 0; i < n; i++) {
        scanf(" %c", &inorder[i]);
    }

    printf("Enter the preorder traversal: ");

    for (i = 0; i < n; i++) {
        scanf(" %c", &preorder[i]);
    }

    int preorderIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preorderIndex);

    // Print inorder traversal of the constructed tree to verify
    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
