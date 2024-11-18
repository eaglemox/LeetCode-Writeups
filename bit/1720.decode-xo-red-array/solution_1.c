/*
 * @lc app=leetcode id=1720 lang=c
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    // Use the first element and the encoded array to decode the original array
    // encoded[i] = orignal[i] ^ original[i+1], encodedSize = originalSize - 1
    // Time: O(N), Space: O(N)
    *returnSize = encodedSize + 1;
    int *result = malloc(*returnSize * sizeof(int));
    result[0] = first;
    for (int i = 0; i < encodedSize; i++) {
        result[i+1] = encoded[i] ^ result[i];
    }
    return result;
}
// @lc code=end

