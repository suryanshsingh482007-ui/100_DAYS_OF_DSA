#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    if (scanf("%s", s) != 1) return 0;

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}