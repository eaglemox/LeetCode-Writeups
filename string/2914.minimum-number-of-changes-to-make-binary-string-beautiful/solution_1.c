/*
 * @lc app=leetcode id=2914 lang=c
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
int minChanges(char* s) {
    // To make the string beautiful, every substring must be same value
    // Minimal substring with length of 2 can achieve minimum number of changes
    // Time: O(N), Space: O(1)
    int changes = 0;
    for (int i = 0; s[i] != '\0'; i += 2) { // two char per step
        if (s[i] != s[i+1]) {changes++;}
    }
    return changes;
}
// @lc code=end

