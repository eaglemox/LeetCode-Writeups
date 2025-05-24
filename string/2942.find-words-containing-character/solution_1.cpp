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
        
        for (int i = 0; i < words.size(); i++) {
            for (char &c : words[i]) {
                if (c == x) {
                    result.push_back(i);
                    break;
                }
            }
        }

        return result;
    }
};
// @lc code=end

