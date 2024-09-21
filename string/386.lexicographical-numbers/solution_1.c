/*
 * @lc app=leetcode id=386 lang=c
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareDigits(const void* a, const void* b) {
    char _a[6], _b[6]; // maximum {5,0,0,0,0,'\0'}
    sprintf(_a, "%d", *(int *)a);
    sprintf(_b, "%d", *(int *)b);
    int lenA = strlen(_a), lenB = strlen(_b);
    int isSwap = 0;
    for (int i = 0; i < lenA && i < lenB; i++) {
        if (_a[i] == _b[i]) { // compare next digit
            continue;
        } else if (_a[i] > _b[i]) {
            isSwap = 1;
            break;
        } else {
            break;
        }
    }
    // this is not required bc. original array is in ascending order, no LenA > LenB condition
    if (lenA > lenB) { // 10x, 10 cannot be detected from first two digits
        isSwap = 1;
    }
    return (isSwap) ? 1 : -1;
}
int* lexicalOrder(int n, int* returnSize) {
    // This is not a valid solution satisfies the Time complexity in O(n) and Space complexity in O(1)
    int *result = malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        result[i] = i + 1;
    }
    qsort(result, n, sizeof(int), compareDigits);
    return result;
}
// @lc code=end

