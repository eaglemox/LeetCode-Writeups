/*
 * @lc app=leetcode id=1550 lang=c
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] & 1) {
            if (++count == 3) {return true;}
        } else {
            count = 0;
        }
    }

    return false;
}
// @lc code=end

