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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) {return;}
    int i = left - 1, j = right + 1;
    int pivot = arr[left + (right - left) / 2];
    int pivotBits = countBits(pivot);

    while (i < j) {
        int bits;
        do {bits = countBits(arr[++i]);}
        while(bits < pivotBits ||
              bits == pivotBits && arr[i] < pivot);
        do {bits = countBits(arr[--j]);}
        while(bits > pivotBits ||
              bits == pivotBits && arr[j] > pivot);

        if (i >= j) {break;}
        swap(&arr[i], &arr[j]);
    }

    mergeSort(arr, left, i - 1);
    mergeSort(arr, j + 1, right);
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    // Quick sort, compare number of setbits then value, Time: O(NlogN~N^2), Space: O(N)
    *returnSize = arrSize;
    mergeSort(arr, 0, arrSize - 1);
    
    return arr;
}
// @lc code=end

