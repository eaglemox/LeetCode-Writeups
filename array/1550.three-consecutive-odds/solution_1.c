/*
 * @lc app=leetcode id=1550 lang=c
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    for (int i = 0; i < arrSize - 2; i++) {
        if (arr[i] & 1 && arr[i+1] & 1 && arr[i+2] & 1) {
            return true;
        }
    }

    return false;
}
// @lc code=end

