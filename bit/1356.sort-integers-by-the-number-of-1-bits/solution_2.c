/*
 * @lc app=leetcode id=1356 lang=c
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

void merge(int* arr, int left, int right, int middle) {
    int i = left, j = middle + 1, index = 0;
    int length = right - left + 1;
    int *merged = malloc(length * sizeof(int));

    int leftBits, rightBits;
    while (i <= middle && j <= right) {
        leftBits = countBits(arr[i]);
        rightBits = countBits(arr[j]);
        if (leftBits == rightBits) {
            merged[index++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        } else {
            merged[index++] = (leftBits < rightBits) ? arr[i++] : arr[j++];
        }
    }
    while (i <= middle) {
        merged[index++] = arr[i++];
    }
    while (j <= right) {
        merged[index++] = arr[j++];
    }
    for (int i = 0; i < length; i++) {
        arr[left+i] = merged[i];
    }
    free(merged);
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) {return;}
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right, mid);
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    // Merge sort, Time: O(NlogN), Space: O(N)
    *returnSize = arrSize;
    mergeSort(arr, 0, arrSize - 1);
    
    return arr;
}
// @lc code=end

