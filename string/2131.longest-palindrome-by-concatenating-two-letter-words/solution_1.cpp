/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int length = 0;
        unordered_map<string, int> count;

        for (string &word: words) {
            string rev = word; 
            swap(rev[0], rev[1]); // reverse string
            if (count[rev]) {
                count[rev]--;
                length += 4;
            } else {
                count[word]++;
            }
        }

        for (int i = 0; i < 26; i++) {
            string same(2, i + 'a');
            if (count[same]) {
                length += 2;
                break;
            }
        }

        return length;
    }
};
// @lc code=end

