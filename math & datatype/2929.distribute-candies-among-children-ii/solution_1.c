/*
 * @lc app=leetcode id=2929 lang=c
 *
 * [2929] Distribute Candies Among Children II
 */

// @lc code=start
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

long long distributeCandies(int n, int limit) {
    // Only three children to distribute, we can use for loops to find each possible combination
    long long result = 0;
    for (int i = 0; i <= min(limit, n); i++) {
        // Last two children share remaining (n - i) candies
        if (n - i > 2 * limit) {continue;}
        // Possible second child condition - third child's candies > limit
        result += max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
    }

    return result;
}
// @lc code=end

