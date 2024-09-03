/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
void swap(int *num1, int *num2) {
    int temp;
    // printf("%d, %d\n", *num1, *num2);
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 1) {return 1;}
    int count = 0; // unique numbers
    int temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != temp) {
            count++;
            swap(&nums[count], &nums[i]);
            temp = nums[count];
        }
    }
    return count + 1; // add initial
}
// @lc code=end

