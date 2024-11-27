/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char* s, int sSize) {
    // Two pointer iteration
    // Time: O(N), Space: O(1)
    int i = 0, j = sSize - 1;
    while (i < j) {
        swap(&s[i++], &s[j--]);
    }
}
// @lc code=end

