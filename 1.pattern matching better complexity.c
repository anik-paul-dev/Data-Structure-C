#include <stdio.h>
#include <string.h>

int binarySearch(char *text, char *pattern, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;

        int i = mid, j = 0;
        while (i < strlen(text) && j < strlen(pattern) && text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == strlen(pattern))
            return mid;
        else if (i == strlen(text) || text[i] > pattern[j])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int patternMatch(char *text, char *pattern) {
    return binarySearch(text, pattern, 0, strlen(text) - strlen(pattern));
}

int main() {
    char text[] = "abracadabra";
    char pattern[] = "cad";

    int index = patternMatch(text, pattern);

    if (index != -1)
        printf("Pattern found at index %d\n", index);
    else
        printf("Pattern not found\n");

    return 0;
}
