/*
 * @lc app=leetcode id=769 lang=c
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int maxChunksToSorted(int* arr, int arrSize) {
    // Greedly split chunks, find the maxNum of arr[:i] less than i to create new chunk
    // Time: O(N), Space: O(1) 
    int chunks = 0, maxNum = 0;
    for (int i = 0; i < arrSize; i++) {
        maxNum = max(maxNum, arr[i]);
        if (maxNum <= i) {
            chunks++;
        }
    }
    return chunks;
}
// @lc code=end

