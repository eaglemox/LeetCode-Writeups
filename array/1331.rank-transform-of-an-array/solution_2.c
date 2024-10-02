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

typedef struct {
    int idx;
    int val;
} Map;

int cmp(const void* a, const void* b) {
    // sort in ascending order
    return ((Map *)a)->val - ((Map *)b)->val;
}

// void printArray(const int* arr, int len) {
//     for (int i = 0; i < len; i++) {
//         printf("%d ", arr[i]);
//         if (i == len - 1) {printf("\n");}
//     }
// }

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize; // first assign returnSize
    // if (arrSize == 0) {return NULL;}
    Map *lookupTable = malloc(arrSize * sizeof(Map));
    for (int i = 0; i < arrSize; i++) {
        lookupTable[i] = (Map){.idx = i, .val = arr[i]};
    }
    qsort(lookupTable, arrSize, sizeof(Map), cmp);

    int *result = calloc(arrSize, sizeof(int));
    for (int i = 0, rank = 1; i < arrSize; i++) {
        // printf("idx: %d, val: %d\n", lookupTable[i].idx, lookupTable[i].val);
        result[lookupTable[i].idx] = rank;
        if (i < arrSize - 1) {
            if (lookupTable[i+1].val != lookupTable[i].val) {rank++;}
        } 
        // else {rank++;}
    }
    return result;
}
// @lc code=end

