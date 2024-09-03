/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int chkCarry = digitsSize - 1;
    // Find the last index where a carry might occur (viewing from the end of the digits array)
    for (chkCarry; chkCarry >= 0 && digits[chkCarry] == 9; chkCarry--) {}
    *returnSize = digitsSize + (chkCarry < 0);
    int *result = malloc(*returnSize * sizeof(int));
    // Copy the original digits into the result array, setting digits after the carry index to 0
    for (int i = 0; i < digitsSize; i++) {
        result[i + (chkCarry < 0)] = (i > chkCarry) ? 0 : digits[i];
    }
    // If all digits were 9, add a 1 at the start; otherwise, increment the digit at the carry index
    (chkCarry < 0) ? result[0] = 1 : result[chkCarry]++;
    return result;
}
// @lc code=end

