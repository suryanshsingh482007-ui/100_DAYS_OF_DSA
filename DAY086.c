#include <stdio.h>

int integerSquareRoot(int n) {
    if (n < 2) return n;

    int left = 1, right = n / 2;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if ((long long)mid * mid <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n >= 0) {
        printf("%d\n", integerSquareRoot(n));
    }

    return 0;
}