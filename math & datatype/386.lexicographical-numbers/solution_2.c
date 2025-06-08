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

void fill(int* list, int curr, int n, int* index) {
    list[(*index)++] = curr;

    if (curr * 10 <= n) {
        fill(list, curr * 10, n, index);
    }
    if ((curr + 1) % 10 == 0) {return;} // Back to previous place
    if (curr < n) {
        fill(list, curr + 1, n, index);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    // Simulate trie to return list of integers in lexicographical order
    int idx = 0;
    int *result = malloc(n * sizeof(int));
    *returnSize = n;

    fill(result, 1, n, &idx);

    return result;
}
// @lc code=end

