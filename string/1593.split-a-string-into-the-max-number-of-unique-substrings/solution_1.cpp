/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        // Recursive backtracking, Time: O(N*2^N), Space: O(N)
        unordered_set<string> substringSet;
        return backtracking(s, 0, substringSet);
    }
private:
    int backtracking(string& s, int index, unordered_set<string> subset) {
        // Return maximum subset size for string[index:]
        int len = s.size();
        if (index == len) {return 0;} // base case
        int count = 0;
        for (int i = 1; i <= len - index; i++) { // length of substring, O(N)
            string substring = s.substr(index, i);
            if (subset.find(substring) == subset.end()) { // is possible subset
                subset.insert(substring);
                // max subset size = current max (without substring)
                //                or current substring + max of latter part of the string
                count = max(count, 1 + backtracking(s, index + i, subset));
                subset.erase(substring);
            }
        }
        return count;
    }
};
// @lc code=end

