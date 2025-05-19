/*
 * @lc app=leetcode id=3024 lang=c
 *
 * [3024] Type of Triangle
 */

// @lc code=start
char* triangleType(int* nums, int numsSize) {
    // Leetcode you serious?
    if (nums[0] + nums[1] > nums[2] && nums[0] + nums[2] > nums[1] && nums[1] + nums[2] > nums[0]) {
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
            return "scalene";
        } else {
            return "isosceles";
        }
    } else {
        return "none";
    }
}
// @lc code=end

