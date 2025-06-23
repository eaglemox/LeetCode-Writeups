/*
 * @lc app=leetcode id=2081 lang=c
 *
 * [2081] Sum of k-Mirror Numbers
 */

// @lc code=start
#include <stdbool.h>

bool isPalindrome(long long base10, int k, int* digits) {
    int len = 0;
    while (base10 > 0) {
        digits[len++] = base10 % k;
        base10 /= k;
    }

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (digits[i] != digits[j]) {
            return false;
        }
    }

    return true;
}

long long kMirror(int k, int n) {
    int left = 1, count = 0, digits[100];
    long long result = 0;

    while (count < n) {
        int right = left * 10;

        for (int par = 0; par < 2; par++) { // parity: 0 -> odd, 1 -> even (palindrome with odd length is shorter)
            for (int i = left; i < right && count < n; i++) {
                long long combined = i;
                // Append last non-center letters to make palindrome
                int x = (par == 0 ? i / 10 : i);
                while (x > 0) {
                    combined = combined * 10 + x % 10;
                    x /= 10;
                }
                if (isPalindrome(combined, k, digits)) {
                    result += combined;
                    count++;
                }
            }
        }

        left = right;
    }

    return result;
}
// @lc code=end