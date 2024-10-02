/*
 * @lc app=leetcode id=1331 lang=c
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    int _a = *(int *)a, _b = *(int *)b;
    return _a - _b;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize; // first assign returnSize
    if (arrSize == 0) {return NULL;}
    int *result = calloc(arrSize, sizeof(int));
    int *arrSort = malloc(arrSize * sizeof(int));
    int **lookupTable = calloc(arrSize, sizeof(int *));
    memcpy(arrSort, arr, arrSize * sizeof(int));
    qsort(arrSort, arrSize, sizeof(int), cmp);
    // for (int i = 0; i < arrSize; i++) {
    //     printf("%d ", arrSort[i]);
    //     if (i == arrSize - 1) {printf("\n");}
    // }
    int rank;
    for (int i = 0, rank = 0; i < arrSize; i++) {
        if (i > 0) {
            if (arrSort[i] != arrSort[i-1]) {rank++;}
        } else {rank++;}
        lookupTable[i] = malloc(2 * sizeof(int));
        lookupTable[i][0] = arrSort[i];
        lookupTable[i][1] = rank;
        // printf("key: %d, rank: %d\n", lookupTable[i][0], lookupTable[i][1]);
    }
    for (int i = 0; i < arrSize; i++) {
        int l = 0, r = arrSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[i] == lookupTable[mid][0]) {
                result[i] = lookupTable[mid][1];
                break;
            }
            else if (arr[i] > lookupTable[mid][0]) {
                l = mid + 1;
            }
            else if (arr[i] < lookupTable[mid][0]) {
                r = mid - 1;
            }
        }
    }
    // for (int i = 0; i < arrSize; i++) {
    //     printf("%d ", result[i]);
    //     if (i == arrSize - 1) {printf("\n");}
    // }
    return result;
}
// @lc code=end

