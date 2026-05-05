#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[101];
    int count;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char names[n][101];
    struct Candidate freq[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(freq[j].name, names[i]) == 0) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(freq[uniqueCount].name, names[i]);
            freq[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    char winner[101];
    int maxVotes = -1;

    for (int i = 0; i < uniqueCount; i++) {
        if (freq[i].count > maxVotes) {
            maxVotes = freq[i].count;
            strcpy(winner, freq[i].name);
        } else if (freq[i].count == maxVotes) {
            if (strcmp(freq[i].name, winner) < 0) {
                strcpy(winner, freq[i].name);
            }
        }
    }

    printf("%s\n", winner);

    return 0;
}