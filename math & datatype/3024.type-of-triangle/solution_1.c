/*
 * @lc app=leetcode id=3024 lang=c
 *
 * [3024] Type of Triangle
 */

// @lc code=start
char* triangleType(int* nums, int numsSize) {
    // Leetcode you serious?
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= (nums[(i+1)%numsSize] + nums[(i+2)%numsSize])) {
            return "none";
        }
    }
    
    if (nums[0] == nums[1] && nums[0] == nums[2]) {
        return "equilateral";
    } else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
        return "scalene";
    }

    return "isosceles";
}
// @lc code=end

