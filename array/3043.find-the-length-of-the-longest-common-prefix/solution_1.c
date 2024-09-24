/*
 * @lc app=leetcode id=3043 lang=c
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
#include <math.h>
#include <stdlib.h>
#include "uthash.h"
#define max(a, b) ((a > b) ? a : b)

typedef struct {
    int val;
    UT_hash_handle hh;
} hashMap;

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    hashMap *prefix = NULL, *temp, *iter;
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        int val = arr1[i];
        while (val > 0) {
            // insert prefix into prefix hashmap
            HASH_FIND_INT(prefix, &val, temp);
            // not found in hash
            if (temp == NULL) {
                temp = malloc(sizeof(hashMap));
                *temp = (hashMap){val};
                HASH_ADD_INT(prefix, val, temp);
            }
            val /= 10;
        }
    }
    for (int i = 0; i < arr2Size; i++) {
        int val = arr2[i];
        while (val > 0) { // check all prefix of numbers in arr2
            HASH_FIND_INT(prefix, &val, temp);
            // found in hash
            if (temp != NULL) {
                count = max(count, (int)log10(val) + 1);
                break;
            }
            val /= 10;
        }
    }

    HASH_ITER(hh, prefix, iter, temp) {
        HASH_DEL(prefix, iter);
        free(iter);
    }
    return count;
}
// @lc code=end

