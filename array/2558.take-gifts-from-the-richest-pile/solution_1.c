/*
 * @lc app=leetcode id=2558 lang=c
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
#include <math.h>
#include <stdlib.h>

long long pickGifts(int* gifts, int giftsSize, int k) {
    // Brute force, try to find richest pile and leave with floor(sqrt(gifts[i])) every second
    // Time: O(k*N), Space: O(1)
    while (k > 0) {
        int richest = 0;
        for (int i = 1; i < giftsSize; i++) {
            if (gifts[i] > gifts[richest]) {
                richest = i;
            }
        }
        gifts[richest] = floor(sqrt(gifts[richest]));
        k--;
    }
    // Summing the remaining gifts
    long long result = 0;
    for (int i = 0; i < giftsSize; i++) {
        result += gifts[i];
    }

    return result;
}
// @lc code=end

