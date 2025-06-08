/*
 * @lc app=leetcode id=386 lang=c
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* lexicalOrder(int n, int* returnSize) {
    // Simulate trie to return list of integers in lexicographical order
    int curr = 1, idx = 0;
    int *result = malloc(n * sizeof(int));
    *returnSize = n;

    while (idx < n) {
        result[idx++] = curr;

        if (curr * 10 <= n) {
            curr *= 10;
        } else if (curr % 10 < 9 && curr < n) {
            curr += 1;
        } else {
            while ((curr / 10) % 10 == 9) { // Carry
                curr /= 10;
            }
            curr = curr / 10 + 1; 
        }
    }

    return result;
}
// @lc code=end

