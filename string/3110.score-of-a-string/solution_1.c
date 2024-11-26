/*
 * @lc app=leetcode id=3110 lang=c
 *
 * [3110] Score of a String
 */

// @lc code=start
int scoreOfString(char* s) {
    // The score is ascii value distance between s[i] and s[i+1]. Simply sum the absolute of each distance
    // Time: O(N), Space: O(1)
    int score = 0;
    for (int i = 1; s[i] != '\0'; i++) {
        score += (s[i] > s[i-1]) ? s[i] - s[i-1] : s[i-1] - s[i];
    }
    return score;
}
// @lc code=end

