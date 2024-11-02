/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start
#include <stdbool.h>

bool isPowerOfFour(int n) {
    // Check n is all possible powers of four within the int range
    // Time: O(15), Space: O(15)
    int pFour[] = {1, 4, 16, 256, 1024, 4096, 16384, 65536, 262144, 1048576,\
                   4194304, 16777216,67108864,268435456,1073741824};
    for (int i = 0; i < 15; i++) {
        if (n == pFour[i]) {return true;}
    }
    return false;
}
// @lc code=end

