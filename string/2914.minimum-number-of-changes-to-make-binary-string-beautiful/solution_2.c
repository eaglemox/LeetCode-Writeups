/*
 * @lc app=leetcode id=2914 lang=c
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
int minChanges(char* s) {
    // Naive appraoch
    // Time: O(N), Space: O(1)
    int changes = 0, sameChars = 1;
    char prev = s[0];
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == prev) {
            sameChars++;
            continue;
        } else {
            prev = s[i];
        }
        if (sameChars % 2) { // substring not beautiful
            sameChars = 0;
            changes++;
        } else {
            sameChars = 1;
        }
    }
    return changes;
}
// @lc code=end

