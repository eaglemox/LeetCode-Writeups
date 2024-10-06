/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
// #include <string>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Two pointer approach, only record the index without prefix & suffix
        // Time: O(min(M,N)), Space: O(M + N)
        if (sentence1 == sentence2) {return true;} // similar contains equal
        vector<string> word1, word2;
        string token;
        stringstream ss(sentence1);
        while (getline(ss, token, ' ')) {
            word1.push_back(token);
        }
        ss.str("");
        ss.clear();
        ss.str(sentence2);
        while (getline(ss, token, ' ')) {
            word2.push_back(token);
        }
        int len1 = word1.size(), len2 = word2.size();
        int commonLen = min(len1, len2);
        int start = 0, end1 = len1 - 1, end2 = len2 - 1;
        // prefix
        while (start < commonLen && word1[start] == word2[start]) {
            start++;
        }
        // suffix: end will goto -1 if sentence only consist of prefix & suffix
        while (end1 >= 0 && end2 >= 0 && word1[end1] == word2[end2]) {
            end1--;
            end2--;
        }
        // check the shorter sentence is prefix + sufffix
        if (len1 < len2) {
            return end1 < start;
        }
        return end2 < start;
    }
};
// @lc code=end

