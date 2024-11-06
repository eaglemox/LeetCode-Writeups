/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    // Set: {1, 2, ..., n} -> Error: 1 duplicate, 1 missing
    // XOR summing the complete set and error set will result in sum = duplicate ^ missing
    // The set bit '1' is either comes from duplicate or missing number
    // Time: O(3N) = O(N), Space: O(1)
    *returnSize = 2;  // {duplicate, missing}
    int xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= i + 1;
        xorSum ^= nums[i];
    }
    // Find least significant (rightmost) set bit of xorSum
    int lsb = 0;
    while ((xorSum & (1 << lsb)) == 0) {
        lsb++;
    }
    
    // If lsb is provided by missing number, the sum1 wil be the missing number
    // while the sum2 be the duplicate number, vice versa
    int xorSum1 = 0, xorSum2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & (1 << lsb)) {
            xorSum1 ^= nums[i];
        } else {
            xorSum2 ^= nums[i];
        }
        if ((i + 1) & (1 << lsb)) {
            xorSum1 ^= i + 1;
        } else {
            xorSum2 ^= i + 1;
        }
    }

    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == xorSum1) { // sum1 is the duplicate number
            result[0] = xorSum1;
            result[1] = xorSum2;
            break;
        }
        if (nums[i] == xorSum2) {// sum2 is the duplicate number
            result[0] = xorSum2;
            result[1] = xorSum1;
            break;
        }
    }
    return result;
}
// @lc code=end

