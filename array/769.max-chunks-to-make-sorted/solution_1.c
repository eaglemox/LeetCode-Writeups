/*
 * @lc app=leetcode id=769 lang=c
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
int maxChunksToSorted(int* arr, int arrSize) {
    // Check if the prefix sum eqauls to the sorted sum
    // Time: O(N), Space: O(1) 
    int chunks = 0, prefixSum = 0, sortedSum = 0;
    for (int i = 0; i < arrSize; i++) {
        prefixSum += arr[i];
        sortedSum += i;
        if (prefixSum == sortedSum) {
            chunks++;
        }
    }
    return chunks;
}
// @lc code=end

