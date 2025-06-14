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
    char max[10], min[10];
    sprintf(max, "%d", num);
    strcpy(min, max);

    int minMap = max[0], maxMap = -1; // First digit of integer must non-zero

    for (int i = 0; min[i] != '\0'; i++) {
        if (min[i] == minMap) {
            min[i] = '0';
        }
    }

    int idx = 0;
    while (max[idx] == '9') { // Skip to first non-nine digit
        idx++;
    }

    for (maxMap = max[idx]; max[idx] != '\0'; idx++) {
        if (max[idx] == maxMap) {
            max[idx] = '9';
        }
    }

    return atoi(max) - atoi(min);
}
// @lc code=end

