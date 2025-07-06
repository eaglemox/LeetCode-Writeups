/*
 * @lc app=leetcode id=1865 lang=c
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define MAX_VAL 1000000000

// Observe the contraints, nums1 have short length with large range
//              while have nums2 have long length with small range
// We can save nums1 with a array and nums2 with a hashmap,
// then iterate nums1 to sum the number of tot - nums1[i] exist in nums2

typedef struct {
    int *nums1;
    int nums1Size;
    int *nums2;
    int nums2Size;
    int *nums2Map;
} FindSumPairs;


FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    FindSumPairs *ret = malloc(sizeof(FindSumPairs));

    ret->nums1 = malloc(nums1Size * sizeof(int));
    memcpy(ret->nums1, nums1, nums1Size * sizeof(int));
    ret->nums1Size = nums1Size;

    ret->nums2 = malloc(nums2Size * sizeof(int));
    memcpy(ret->nums2, nums2, nums2Size * sizeof(int));
    ret->nums2Size = nums2Size;

    ret->nums2Map = calloc(MAX_VAL + 1, sizeof(int));
    for (int i = 0; i < nums2Size; i++) {
        ret->nums2Map[nums2[i]]++;
    }

    return ret;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {
    if (index < 0 || index >= obj->nums2Size) {return;}

    int *target = &obj->nums2[index];
    obj->nums2Map[*target]--;

    *target += val;
    if (*target >= MAX_VAL) {
        printf("%d exceed range of nums2 after adding %d\n", *target, val);
        return;
    }
    obj->nums2Map[*target]++;
}

int findSumPairsCount(FindSumPairs* obj, int tot) {
    int ret = 0;
    for (int i = 0; i < obj->nums1Size; i++) {
        int num1 = obj->nums1[i];
        if (num1 >= tot) {continue;}

        // Check if target exceed range of nums2
        int target = tot - num1;
        if (target > MAX_VAL) {continue;}
        ret += obj->nums2Map[target];
    }

    return ret;
}

void findSumPairsFree(FindSumPairs* obj) {
    free(obj->nums1);
    free(obj->nums2);
    free(obj->nums2Map);
    free(obj);
}

/**
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);
 
 * int param_2 = findSumPairsCount(obj, tot);
 
 * findSumPairsFree(obj);
*/
// @lc code=end

