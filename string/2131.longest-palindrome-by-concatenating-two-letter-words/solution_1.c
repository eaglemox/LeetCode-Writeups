/*
 * @lc app=leetcode id=2131 lang=c
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
int longestPalindrome(char** words, int wordsSize) {
    // All word combination 26 * 26 = 676
    int length = 0;
    int count[26*26] = {0}; // map of word count
    for (int i = 0; i < wordsSize; i++) {
        int first = words[i][0] - 'a', second = words[i][1] - 'a';
        if (count[second*26+first]) {
            count[second*26+first]--;
            length += 4;
        } else {
            count[first*26+second]++;
        }
    }
    // Single word palindrome without pair
    for (int i = 0; i < 26; i++) {
        if (count[i*26+i]) {
            length += 2;
            break; // can only have 'one' single word palindrome at the center
        }
    }
    return length;
}
// @lc code=end

