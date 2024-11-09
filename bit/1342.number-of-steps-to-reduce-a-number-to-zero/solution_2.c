/*
 * @lc app=leetcode id=1342 lang=c
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
int numberOfSteps(int num) {
    // Steps: subtraction + division
    // = number of '1' bits + (bit length - 1)
    // Time: O(logN), Space: O(1), N is bounded [0,1e6] (20 bits)
    if (num == 0) {return 0;}
    int bitCount = 0, bitLength = 0;
    while (num > 0) {
        bitCount += num & 1;
        bitLength++;
        num >>= 1;
    }
    return bitCount + bitLength - 1;
}
// @lc code=end

