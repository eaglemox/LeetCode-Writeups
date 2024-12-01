/*
 * @lc app=leetcode id=1346 lang=c
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
#include <stdbool.h>
#define VAL_RANGE 1000

bool checkIfExist(int* arr, int arrSize) {
    // The range of arr[i] is small enough [-1e3, 1e3] -> 2e3 + 1, we use a array as hashTable
    // Time: O(N), Space: O(2e3) = O(1)
    int count[2*VAL_RANGE+1] = {0}; // [-1e3, 1e3] -> [0, 2e3] (0: 1e3)
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + VAL_RANGE]++;
        if (count[VAL_RANGE] == 2) {return true;} // 0 case
        // Check if 2*arr[i] or arr[i]/2 counted
        if (arr[i] >= -500 && arr[i] <= 500 && count[2*arr[i]+VAL_RANGE] == 1) {return true;}
        if (arr[i] % 2 == 0 && count[arr[i]/2+VAL_RANGE] == 1) {return true;}
    }
    return false;
}
// @lc code=end

