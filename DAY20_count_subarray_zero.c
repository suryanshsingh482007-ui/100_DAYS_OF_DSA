#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Hash array to store frequency of prefix sums
    int hash[2 * MAX + 1] = {0};

    // Offset to handle negative prefix sums
    int offset = MAX;

    // Initially prefix sum 0 occurs once
    hash[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(hash[prefix_sum + offset] > 0) {
            count += hash[prefix_sum + offset];
        }

        hash[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}