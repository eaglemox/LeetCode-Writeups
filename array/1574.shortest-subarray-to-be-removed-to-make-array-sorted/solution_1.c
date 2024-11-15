/*
 * @lc app=leetcode id=1574 lang=c
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
#define min(a, b) ((a < b) ? a : b)

int findLengthOfShortestSubarray(int* arr, int arrSize) {
    // The elements in result array are non-descending
    // Time: O(N), Space: O(1)
    int i = 0, j = arrSize - 1;
    while (j > 0 && arr[j-1] <= arr[j]) {j--;}
    int length = j; // 0~j
    while (i < j && (i == 0 || arr[i] >= arr[i-1])) {
        while (j < arrSize && arr[i] > arr[j]) {j++;} // j step back
        length = min(length, j - i - 1); // j - (i+1)
        i++;
    }
    return length;
}
// @lc code=end

