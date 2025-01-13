/*
 * @lc app=leetcode id=3223 lang=c
 *
 * [3223] Minimum Length of String After Operations
 */

// @lc code=start
#include <string.h>

int minimumLength(char* s) {
    // Compute the result length after counting frequency
    // Time: O(N), Space: O(1)
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i]-'a']++;
    }
    int result = 0;
    for (int i = 0; i < 26; i++) {
        // If the frequency of the letter is odd  -> 1 length after operations
        //                                   even -> 2 length after operations
        if (freq[i]) {
            result += 2 - (freq[i] & 1); // (num & 1) == (num % 2)
        }
    }
    return result;
}
// @lc code=end

