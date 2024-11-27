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
    // Odd: swap left & right except for center char
    // Even: swap all char pairs
    // Time: O(N), Space: O(1)
    for (int i = 0; i < sSize / 2; i++) {
        swap(&s[i], &s[sSize-1-i]); 
    }
}
// @lc code=end

