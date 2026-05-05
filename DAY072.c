#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char findFirstRepeated(char* s) {
    bool seen[26] = {false};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (seen[index]) {
            return s[i];
        }
        seen[index] = true;
    }

    return '\0';
}

int main() {
    char s[100];
    if (scanf("%s", s) != 1) return 0;

    char result = findFirstRepeated(s);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}