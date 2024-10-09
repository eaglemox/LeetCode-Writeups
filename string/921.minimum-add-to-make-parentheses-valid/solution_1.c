/*
 * @lc app=leetcode id=921 lang=c
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
int minAddToMakeValid(char* s) {
    int left = 0, right = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            left++;
        } else if (left > 0) {
            left--;
        } else {
            right++;
        }
    }
    return left + right;
}
// @lc code=end

