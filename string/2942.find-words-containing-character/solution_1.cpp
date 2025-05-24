/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int i = 0;
        for (string &word : words) {
            for (char &c : word) {
                if (c == x) {
                    result.push_back(i);
                    break;
                }
            }
            i++;
        }
        return result;
    }
};
// @lc code=end

