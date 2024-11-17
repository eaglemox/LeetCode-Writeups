/*
 * @lc app=leetcode id=862 lang=c
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
#include <stdlib.h>
#define min(a, b) ((a < b) ? a : b)
#define QUEUE_SIZE 100001 // I'm lazy to write queue struct

int shortestSubarray(int* nums, int numsSize, int k) {
    // Queue approach to search the number range with sum at least k
    // Time: O(N), Space: O(N)
    int minLength = numsSize + 1; // any length exceed the numsSize
    long long *prefix = malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 1; i <= numsSize; i++) { // 0~i-1 sum
        prefix[i] = prefix[i-1] + nums[i-1];
    }
    int qfront = 0, qback = -1;
    int *queue = malloc(QUEUE_SIZE * sizeof(int));

    // i equal to right index + 1 -> length become i - left index
    for (int i = 0; i <= numsSize; i++) {
        while (qback >= qfront && prefix[i] - prefix[queue[qfront]] >= k) {
            minLength = min(minLength, i - queue[qfront]);
            qfront++;
        }
        // Remove larger prefix to shrink the length (negative value occurred)
        while (qback >= qfront && prefix[queue[qback]] >= prefix[i]) {
            qback--;
        }
        queue[++qback] = i;
    }
    return (minLength <= numsSize) ? minLength : -1;
}
// @lc code=end

