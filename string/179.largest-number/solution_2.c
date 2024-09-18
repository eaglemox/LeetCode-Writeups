/*
 * @lc app=leetcode id=179 lang=c
 *
 * [179] Largest Number
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b) {
    char strAB[20], strBA[20];
    sprintf(strAB,"%d%d", *(int *)a, *(int *)b);
    sprintf(strBA,"%d%d", *(int *)b, *(int *)a);
    return strcmp(strBA, strAB);
}
char* largestNumber(int* nums, int numsSize) {
    int length = 0;
    for (int i = 0; i < numsSize; i++) {
        // compute length
        int temp = nums[i];
        if (temp == 0) {length++;}
        while (temp > 0) {
            length++;
            temp /= 10;
        }
    }
    printf("total length: %d\n", length);

    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] == 0) {return "0";}

    char *result = malloc((length + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        char buffer[10];
        snprintf(buffer, 10, "%d", nums[i]);
        printf("%s ", buffer);
        strcat(result, buffer);
    }
    
    return result;
}
// @lc code=end

