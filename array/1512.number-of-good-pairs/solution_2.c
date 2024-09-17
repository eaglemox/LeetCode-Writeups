/*
 * @lc app=leetcode id=1512 lang=c
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#define NUM_MAX_VAL 101
int numIdenticalPairs(int* nums, int numsSize) {
    int hashmap[NUM_MAX_VAL] = {0};
    // track total pairs count using hashmap[0]
    for (int i = 0; i < numsSize; i++) {
        // total pair of number X
        // 1 + 2 + 3 + ... n = n * (n-1) / 2
        hashmap[0] += hashmap[nums[i]]++;
    }

    return hashmap[0];
}
// @lc code=end

