/*
 * @lc app=leetcode id=2070 lang=c
 *
 * [2070] Most Beautiful Item for Each Query
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(a, b) ((a > b) ? a : b)

int cmpItem(const void* a, const void* b) {
    int **_a = (int **)a, **_b = (int **)b;
    if (_a[0][0] == _b[0][0]) { // same price
        return _a[0][1] - _b[0][1];
    } else {
        return _a[0][0] - _b[0][0];
    }
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    // Sort items in ascending order then use binary search to find max beauty of the query
    // Time: O((M+N)logN), Space: O(N), M: queriesSize, N: itemsSize
    *returnSize = queriesSize;
    qsort(items, itemsSize, sizeof(int *), cmpItem);
    int maxBeauty = items[0][1];
    for (int i = 1; i < itemsSize; i++) {
        items[i][1] = maxBeauty = max(maxBeauty, items[i][1]);
    }

    int *result = malloc(queriesSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {result[i] = 0;}
    
    for (int i = 0; i < queriesSize; i++) {
        int mid;
        int left = 0, right = itemsSize - 1, maxBeauty = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= queries[i]) {
                // update maxBeauty with lesser price
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[i] = maxBeauty;
    }
    return result;
}
// @lc code=end

