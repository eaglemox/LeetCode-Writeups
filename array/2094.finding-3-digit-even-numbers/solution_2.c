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

    for (int i = 1; i < 10; i++) {
        if (count[i] <= 0) {continue;}
        count[i]--;
        for (int j = 0; j < 10; j++) {
            if (count[j] <= 0) {continue;}
            count[j]--;
            for (int k = 0; k < 10; k++) {
                if (count[k] > 0 && !(k & 1)) {
                    result[(*returnSize)++] = i * 100 + j * 10 + k;
                }
            }
            count[j]++;
        }
        count[i]++;
    }

    return result;
}
// @lc code=end

