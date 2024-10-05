/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Count substring of s2, M = s1.length, N = s2.length
        // Time: O(N + (N-M) * (M + 26)) = O(MN), Space: O(2 * 26) = O(1)
        int len1 = s1.size(), len2 = s2.size();
        int count1[26] = {0};
        for (char c : s1) {
            count1[c-'a']++;
        }
        for (int i = 0; i < len2 - len1 + 1; i++) {
            int count2[26] = {0};
            for (char c : s2.substr(i, len1)) {
                count2[c-'a']++;
            }
            bool isPermutation = true;
            for (int j = 0; j < 26; j++) {
                if (count1[j] != count2[j]) {
                    isPermutation = false;
                }
            }
            if (isPermutation) {return true;}
        }
        return false;
    }
};
// @lc code=end

