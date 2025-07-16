/*
 * @lc app=leetcode id=3201 lang=c
 *
 * [3201] Find the Maximum Length of Valid Subsequence I
 */

// @lc code=start
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximumLength(int* nums, int numsSize) {
    // The subsequence is valid if each adjacent pair has equal parity of sum value
    // That is even or odd element in the subsequence should have same parity
    // There are four types of valid subsequence
    // 1. All odd elements 2. All even elements 
    // 3/4. Alternating parity start with odd / even element
    int allOdd = 0, allEven = 0;
    int oddStart = 1, evenStart = 1;
    int oddPrev = nums[0], evenPrev = nums[1];

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & 1) {allOdd++;}
        else {allEven++;}

        if ((nums[i] ^ oddPrev) & 1) { // Different parity
            oddPrev = nums[i];
            oddStart++;
        }
        if (i >= 2 && (nums[i] ^ evenPrev) & 1) {
            evenPrev = nums[i];
            evenStart++;
        }
    }

    return max(oddStart, max(evenStart, max(allOdd, allEven)));
}
// @lc code=end

