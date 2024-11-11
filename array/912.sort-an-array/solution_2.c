/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* nums, int left, int right, int mid) {
    int i = left, j = mid + 1, index = 0;
    int length = right - left + 1;
    int *merged = malloc(length * sizeof(int));
    while (i <= mid && j <= right) { // both haven't reached end
        merged[index++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];
    }
    while (i <= mid) {
        merged[index++] = nums[i++];
    }
    while (j <= right) {
        merged[index++] = nums[j++];
    }
    for (int i = 0; i < length; i++) {
        nums[left+i] = merged[i];
    }
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) {return;}
    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, right, mid);
}

int* sortArray(int* nums, int numsSize, int* returnSize) { 
    // Merge sort, Time: O(NlogN), Space: O(N)
    *returnSize = numsSize;
    int *sortedArray = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sortedArray[i] = nums[i];
    }
    mergeSort(sortedArray, 0, numsSize - 1);
    return sortedArray;
}
// @lc code=end

