/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) {
                return false;
            }
        }
        return sentence[0] == sentence[sentence.size()-1];
    }
};
// @lc code=end

