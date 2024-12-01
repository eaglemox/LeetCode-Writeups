/*
 * @lc app=leetcode id=1346 lang=c
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize) {
    // Two pointer approach, checking arr[i+1:] have arr[i]*2 or arr[i]/2
    // Time: O(N^2), Space: O(1)
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] == arr[i] * 2 || (arr[i] % 2 == 0 && arr[j] == arr[i] / 2)) {return true;}
        }
    }

    return false;
}
// @lc code=end

