/*
 * @lc app=leetcode id=1394 lang=c
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
#define MAX_SIZE 501

int findLucky(int* arr, int arrSize) {
    int freq[MAX_SIZE] = {};
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]++;
    }

    // Check from 500 ~ 1
    for (int i = MAX_SIZE - 1; i > 0; i--) {
        if (freq[i] == i) {
            return i;
        }
    }

    return -1;
}
// @lc code=end

