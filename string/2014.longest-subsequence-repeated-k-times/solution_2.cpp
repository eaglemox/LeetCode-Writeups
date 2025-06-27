/*
 * @lc app=leetcode id=2014 lang=cpp
 *
 * [2014] Longest Subsequence Repeated k Times
 */

// @lc code=start
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedK(string substr, string s, int k) {
        int i = 0, count = 0;
        for (char &c : s) {
            if (c == substr[i]) {
                if (++i == substr.size()) {
                    i = 0;
                    if (++count == k) return true; // Reach k times
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> count(26);
        vector<char> candidateChar;

        for (char &c : s) {
            count[c-'a']++;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c-'a'] < k) {continue;}
            candidateChar.push_back(c);
        }

        string result = "";
        queue<string> q;
        q.push("");
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (char &c : candidateChar) {
                string next = curr + c;
                if (repeatedK(next, s, k)) { // First reach 
                    result = next;
                    q.push(next);
                }
            }
        }

        return result;
    }
};
// @lc code=end

