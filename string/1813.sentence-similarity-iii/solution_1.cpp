/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
// #include <string>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> splitString(string str, const char& deli) {
        vector<string> tokens;
        string token;
        stringstream ss(str);
        while (getline(ss, token, deli)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Compare prefix, suffix using vector (deque is more convenient)
        // Time: O(min(M,N)), Space: O(M + N)
        if (sentence1 == sentence2) {return true;} // similar contains equal
        vector<string> word1 = splitString(sentence1, ' ');
        vector<string> word2 = splitString(sentence2, ' ');
        int commonPrefix = 0, commonSuffix = 0;
        int len1 = word1.size(), len2 = word2.size();
        int commonLen = min(len1, len2);
        for (int i = 0; i < commonLen; i++) {
            if (word1[len1-1-i] == word2[len2-1-i]) {
                cout << word1[len1-1-i] << " is common suffix of two sentences" << endl;
                // prevent repeatly count
                word1.pop_back();
                word2.pop_back();
                commonSuffix++;
            }
        }
        for (int i = 0; i < commonLen - commonSuffix; i++) {
            if (word1[i] == word2[i]) {
                cout << word1[i] << " is common prefix of two sentences" << endl;
                commonPrefix++;
            }
        }
        if (commonLen == commonPrefix + commonSuffix) {return true;}
        return false;
    }
};
// @lc code=end

