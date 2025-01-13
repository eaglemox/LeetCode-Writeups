/*
 * @lc app=leetcode id=3223 lang=c
 *
 * [3223] Minimum Length of String After Operations
 */

// @lc code=start
#include <string.h>

int minimumLength(char* s) {
    // The operation choose a character then remove the first same character of left and right side
    // Thus the length after an operation is original length - 2. We only care about the min length, so 
    // only the frequency of characters matters
    // Time: O(N), Space: O(1)
    int len = strlen(s), freq[26] = {0};
    int result = len;
    for (int i = 0; i < len; i++) {
        int letter = s[i]-'a';
        freq[letter]++;
        if (freq[letter] >= 3) {
            freq[letter] -= 2;
            result -= 2;
        }
    }
    return result;
}
// @lc code=end

