/*
 * @lc app=leetcode id=1432 lang=c
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

int maxDiff(int num) {
    // Maximum: change first non-nine digit to '9'
    // Minimum: if first digit is not one, change it to '1' 
    //          else change first non-one and non-zero digit to '0'
    int minMap = -1, maxMap = -1;
    char max[10], min[10];
    
    sprintf(max, "%d", num);
    strcpy(min, max);

    int i;
    for (i = 0; min[i] != '\0'; i++) {
        if (minMap == -1) {
            if (i == 0 && min[i] != '1') {
                minMap = min[i];
            } else if (min[i] != '1' && min[i] != '0') {
                minMap = min[i];
            }
        }
        if (min[i] == minMap) {
            // Check if digit to be change is first digit (before change)
            min[i] = (max[0] == minMap) ? '1' : '0';
        }
    }

    for (i = 0; max[i] != '\0'; i++) {
        if (maxMap == -1 && max[i] != '9') {
            maxMap = max[i];
        }
        if (max[i] == maxMap) {
            max[i] = '9';
        }
    }

    return atoi(max) - atoi(min);
}
// @lc code=end

