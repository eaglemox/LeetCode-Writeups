/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = malloc((digitsSize + 1) * sizeof(int)); // carry
    int index = digitsSize - 1; // interates throgh digitsSize backward
    int carry = 1;

    do {
        result[index + 1] = (digits[index] + carry) % 10;
        carry = (digits[index] + carry) / 10;
        index--;
    }
    while (index >= 0); 

    if (!carry) {
        memmove(result, result + 1, digitsSize * sizeof(int));
        *returnSize = digitsSize;
    } else {
        result[0] = 1;
        *returnSize = digitsSize + 1;
    }
    return result;
}
// @lc code=end

