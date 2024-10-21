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
        int maxCount = 0;
        unordered_set<string> substringSet;
        backtracking(s, 0, 0, maxCount, substringSet);
        return maxCount;
    }
private:
    void backtracking(string& s, int index, int count, int& maxCount, unordered_set<string> subset) {
        // Return maximum subset size for string[index:]
        int len = s.size();
        // Prune branch that cannot have larger subset size
        if (count + (len - index) <= maxCount) {return;}
        // base case: end of string
        if (index == len) {
            maxCount = max(maxCount, count); // update max
            return;
        } 
        for (int i = 1; i <= len - index; i++) { // length of substring, O(N)
            string substring = s.substr(index, i);
            if (subset.find(substring) == subset.end()) { // is possible subset
                subset.insert(substring);
                // max subset size = current max (without substring)
                //                or current substring + max of latter part of the string
                backtracking(s, index + i, 1 + count, maxCount, subset);
                subset.erase(substring);
            }
        }
    }
};
// @lc code=end

