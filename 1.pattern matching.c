#include <stdio.h>

int search(char *text, char *pattern) {
  int i, j;
  for (i = 0; text[i] != '\0'; i++) {
    for (j = 0; pattern[j] != '\0' && text[i + j] == pattern[j]; j++);

    if (pattern[j] == '\0') {
      return i+1;
    }
  }
  return -1;
}
int main() {
  char text[] = "hi hello! how are you?";
  char pattern[] = "how";

  int index = search(text, pattern);

  if (index != -1) {
    printf("Pattern found at index: %d\n", index);
  } else {
    printf("Pattern not found\n");
  }
  return 0;
  }
