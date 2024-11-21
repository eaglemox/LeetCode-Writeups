/*
 * @lc app=leetcode id=2527 lang=c
 *
 * [2527] Find Xor-Beauty of Array
 */

// @lc code=start
int xorBeauty(int* nums, int numsSize) {
    // For the XOR of effective values: (vi | vj) & vk, (vi | vj) & vk = (vj | vi) & vk
    // Furthermore, vi & vk = vk & vi -> (vi & vk) ^ (vk & vi) == 0
    // The XOR of effective values where i != j != k will cancel each other out.
    // The effective values that contribute to the xor-beauty are those where the indices i, j, and k are identical.
    // Time: O(N), Space: O(1)
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}
// @lc code=end

