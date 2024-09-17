/*
 * @lc app=leetcode id=1512 lang=c
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#define NUM_MAX_VAL 101
int numIdenticalPairs(int* nums, int numsSize) {
    if (numsSize == 1) {return 0;}
    int freq[NUM_MAX_VAL] = {0}, count = 0;
    for (int i = 0; i < numsSize; i++) {freq[nums[i]]++;}
    for (int i = 0; i < NUM_MAX_VAL; i++) {
        if (freq[i] > 0) {
            count += freq[i] * (freq[i] - 1) / 2;
        }
    }
    return count;
}
// @lc code=end

