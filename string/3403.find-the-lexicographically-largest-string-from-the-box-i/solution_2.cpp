/*
 * @lc app=leetcode id=3403 lang=cpp
 *
 * [3403] Find the Lexicographically Largest String From the Box I
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string LargestSubstring(string s) {
        // Return the largest substring in lexicalgraphical order
        // Sliding window with two pointer i, j.
        // i: compared substring start index
        // j: next substring start index
        // k: is the length of substring
        int i = 0, j = 1, k = 0;
        while (j + k < s.size()) {
            if (s[i+k] == s[j+k]) {
                k++;
            } else if (s[i+k] > s[j+k]) { 
                // First k-1 letter is identical, repeatedly finding j+1 ~ j+k-1 cannot find larger substring
                // Skip s[j,...,j+k] and advance to s[j+k+1]
                j = j + k + 1;
                k = 0;
            } else {
                // Skip s[i,...,i+k] and advance to s[i+k+1] or s[j] (if i+k+1 ~ j already explored by j)
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
        }

        return s.substr(i);
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {return word;}
        int n = word.size(), maxLength = n - numFriends + 1; // Maximum length of single split (other splits with length 1)
        string result = LargestSubstring(word);

        return result.substr(0, min(n, maxLength));
    }
};
// @lc code=end

