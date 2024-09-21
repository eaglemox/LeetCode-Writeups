/*
 * @lc app=leetcode id=386 lang=c
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* lexicalOrder(int n, int* returnSize) {
    // Time complexity: O(n), Space complexity: O(1)
    // Must create in lexical order
    int *result = malloc(n * sizeof(int));
    *returnSize = n;
    int nextNum = 1; // always first number
    for (int i = 0; i < n; i++) {
        result[i] = nextNum;
        // 1 -> 10 -> 100 -> ... and 119 -> 12 -> 120 -> ... (< n)
        if (nextNum * 10 <= n) {
            nextNum *= 10;
        } else {
            while ((nextNum % 10 == 9) || nextNum >= n) {
                // carry and reach max number -> remove last digit
                nextNum /= 10;
            }
            // increment
            nextNum++;
        }
    
    }
    return result;
}
// @lc code=end

