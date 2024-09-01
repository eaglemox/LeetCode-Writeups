/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

// @lc code=start
int singleNumber(int* nums, int numsSize) {
    int buffer = 0;
    // XOR is associative and A ^ A = 0, A ^ 0 = A
    // -> if every element appears twice except for one,
    // the XOR of every element is the element appears only once.
    // A ^ A ^ B ^ C ^ C ^ .... = 0 ^ B ^ 0 ... ^ 0 = B  
    for (int i = 0; i < numsSize; i++) {
        buffer = buffer ^ nums[i];
    }
    return buffer;
}
// @lc code=end

