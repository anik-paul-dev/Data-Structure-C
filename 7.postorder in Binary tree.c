#include <stdio.h>
#include <stdlib.h>

void postorderTraversal(int tree[], int index, int size) {
    if (index >= size || tree[index] == -1) {
        return;
    }

    postorderTraversal(tree, 2 * index + 1, size);

    postorderTraversal(tree, 2 * index + 2, size);

    printf("%d ", tree[index]);
}

int main() {
    int size;


    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &size);

    int* tree = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the binary tree (use -1 for no node):\n");

    int i;
    for (i = 0; i < size; i++) {
        printf("Node %d: ", i);
        scanf("%d", &tree[i]);
    }

    printf("Post-order traversal: ");
    postorderTraversal(tree, 0, size);
    printf("\n");

    free(tree);

    return 0;
}
