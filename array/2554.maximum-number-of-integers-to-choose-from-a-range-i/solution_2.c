/*
 * @lc app=leetcode id=2554 lang=c
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start
int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    // Store banned number in hashtable
    // Time: O(N), Space: O(N)
    int count = 0, banTable[10001] = {0};
    for (int i = 0; i < bannedSize; i++) {
        banTable[banned[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (banTable[i] > 0) {continue;}
        if ((maxSum -= i) >= 0) {
            count++;
        }
    }
    return count;
}
// @lc code=end

