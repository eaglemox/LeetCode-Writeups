/*
 * @lc app=leetcode id=2566 lang=c
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

int minMaxDifference(int num) {
    // To make num maximum by remapping a digit, the first non-nine digit must be remapped to 9
    // While remapping first non-zero digit to 0 will make num minimal
    char digits[10];
    int minMap = -1, maxMap = -1;

    sprintf(digits, "%d", num);

    int len = strlen(digits);
    for (int i = 0; i < len && (minMap == -1 || maxMap == -1); i++) {
        if (digits[i] != '9' && maxMap == -1) {
            maxMap = digits[i];
        }
        if (digits[i] != '0' && minMap == -1) {
            minMap = digits[i];
        }
    }

    int result = 0;
    for (int i = 0; i < len; i++) {
        if (digits[i] == maxMap && digits[i] == minMap) {
            result += 9;
        } else if (digits[i] == maxMap) {
            result += 9 - (digits[i] - '0');
        } else if (digits[i] == minMap) {
            result += digits[i] - '0';
        }
        if (i < len - 1) {
            result *= 10; // Next digit
        }
    }

    return result;
}
// @lc code=end

