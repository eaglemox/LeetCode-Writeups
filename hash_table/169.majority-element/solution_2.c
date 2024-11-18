/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start
int majorityElement(int* nums, int numsSize) {
    // Boyer-Moore majority voting algorithm. It utilize the difference between
    // the votes to find the candidate with majority votes
    // Time: O(N), Space: O(1)
    int candidate, count = 0;
    for (int i = 0; i < numsSize; i++) {
        // Choose new candidate if other candidates' count equal to the current candidate's count
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else {
            (candidate == nums[i]) ? count++ : count--;
        }
    }
    // It is guaranteed candidate have majority of counts
    // The result may fail when testcase do not contain any majority elements
    return candidate;
}
// @lc code=end

