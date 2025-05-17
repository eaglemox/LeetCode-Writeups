/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
    
void sortColors(int* nums, int numsSize) {
    // Because there are only three value in the array {0,1,2}
    // we can sort it by swapping 0 to the head and 2 to the tail
    int i = 0, j = numsSize - 1;
    for (int k = 0; k <= j;) {
        if (nums[k] == 0) {
            swap(&nums[i++], &nums[k++]);
        } else if (nums[k] == 2) {
            swap(&nums[j--], &nums[k]);
        } else {
            k++;
        }
    }
}
// @lc code=end

