/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionArray(int* nums, int left, int right) {
    int mid = left + (right - left) / 2;
    swap(&nums[mid], &nums[right]);
    int pivot = nums[right]; // pivot is the middle element, moved to right
    int j = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(&nums[i], &nums[j]);
            j++;
        }
    }
    swap(&nums[j], &nums[right]);
    return j;
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) {return;}
    int pivotIndex = partitionArray(nums, left, right);
    mergeSort(nums, left, pivotIndex - 1);
    mergeSort(nums, pivotIndex + 1, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) { 
    // Quick sort, Time: O(NlogN) ~ O(N^2), Space: O(N) -> TLE
    *returnSize = numsSize;
    int *sortedArray = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        sortedArray[i] = nums[i];
    }
    mergeSort(sortedArray, 0, numsSize - 1);
    return sortedArray;
}
// @lc code=end

