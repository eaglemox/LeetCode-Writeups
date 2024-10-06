/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
// #include <string>
#include <sstream>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Deque approach, check if the shorter sentence is the prefix + suffix
        // -> can insert sentence inside it to be equal to the other sentence
        // Time: O(min(M,N)), Space: O(M + N)
        if (sentence1 == sentence2) {return true;} // similar contains equal
        deque<string> word1, word2;
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
        // Pop common prefix
        while (!word1.empty() && !word2.empty() && word1.front() == word2.front()) {
            word1.pop_front();
            word2.pop_front();
        }
        // Pop common suffix
        while (!word1.empty() && !word2.empty() && word1.back() == word2.back()) {
            word1.pop_back();
            word2.pop_back();
        }
        // If shorter sentence is the prefix + suffix
        return (word1.empty() || word2.empty());
    }
};
// @lc code=end

