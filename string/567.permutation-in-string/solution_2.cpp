/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Count substring of s2, M = s1.length, N = s2.length
        // Time: O(M + (N-M) * (26)) = O(N), Space: O(2 * 26) = O(1)
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) {return false;} // imposible s2 contains s2 permutation
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < len1; i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if (count1 == count2) {return true;} // directly compare vector
        for (int i = len1; i < len2; i++) {
            count2[s2[i-len1]-'a']--; // remove oldest count
            count2[s2[i]-'a']++; // add new count
            if (count1 == count2) {return true;}
        }
        return false;
    }
};
// @lc code=end

