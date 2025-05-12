/*
 * @lc app=leetcode id=2094 lang=c
 *
 * [2094] Finding 3-Digit Even Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BUF_SIZE 1000

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    // Follow the hint, check if 100 ~ 998 (999 is odd) can be form with given digits
    *returnSize = 0;
    int count[10] = {0};
    int *result = malloc(BUF_SIZE * sizeof(int));
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }

    for (int i = 100; i <= 998; i++) {
        if (i & 1) {continue;}
        int ones = i % 10, tens = (i / 10) % 10, hundreds = (i / 100);
        count[ones]--; count[tens]--; count[hundreds]--;
        if (count[ones] >= 0 && count[tens] >= 0 && count[hundreds] >= 0) {
            result[(*returnSize)++] = i;
        }
        count[ones]++; count[tens]++; count[hundreds]++;
    }

    return result;
}
// @lc code=end

