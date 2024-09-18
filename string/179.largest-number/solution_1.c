/*
 * @lc app=leetcode id=179 lang=c
 *
 * [179] Largest Number
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long power(int base, int degree) {
    if (degree == 0) {return 1;}
    int result = base;
    while (degree > 1) {
        result *= base;
        degree--;
    }
    return result;
}
int getNumLength(int num) {
    if (num == 0) {return 1;}
    int length = 0;
    while (num > 0) {
        length++;
        num /= 10;
    }
    return length;
}
int cmp(const void* a, const void* b) {
    int _a = *(int *)a;
    int _b = *(int *)b;
    printf("comparing %d, %d\n", _a, _b);
    int lenA = getNumLength(_a);
    int lenB = getNumLength(_b);
    // Will cause overflow if a, b are large
    long long ab = _a * power(10, lenB) + _b;
    long long ba = _b * power(10, lenA) + _a;
    /*  ab < ba -> ">0"
     *  ab = ba -> "=0"
     *  ab > ba -> "<0"
     */ 
    printf("%d, %d = %d\n", ab, ba, ab < ba);
    return (ba - ab);
}
char* largestNumber(int* nums, int numsSize) {
    int length = 0;
    for (int i = 0; i < numsSize; i++) {
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

