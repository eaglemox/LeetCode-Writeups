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

int cmpquery(const void* a, const void* b) {
    int **_a = (int **)a, **_b = (int **)b;
    return _a[0][0] - _b[0][0];
}

int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    // Sort items and queries, utilize the ascending property to find the max beauty 
    // with price no greater than query
    // Time: O(MlogM+NlogN), Space: O(M+N), M: queriesSize, N: itemsSize
    *returnSize = queriesSize;
    qsort(items, itemsSize, sizeof(int *), cmpItem);

    int *result = malloc(queriesSize * sizeof(int));
    int **queryMap = malloc(queriesSize * sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = 0;
        queryMap[i] = malloc(2 * sizeof(int));
        queryMap[i][0] = queries[i];
        queryMap[i][1] = i;
    }
    qsort(queryMap, queriesSize, sizeof(int *), cmpquery);
    
    int j = 0, maxBeauty = 0;
    for (int i = 0; i < queriesSize; i++) {
        int queryIndex = queryMap[i][1];
        while (j < itemsSize && items[j][0] <= queries[queryIndex]) {
            maxBeauty = max(maxBeauty, items[queryIndex][1]);
            j++;
        }
        result[i] = maxBeauty;
    }
    return result;
}
// @lc code=end

