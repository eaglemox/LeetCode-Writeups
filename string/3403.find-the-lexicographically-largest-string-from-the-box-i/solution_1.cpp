/*
 * @lc app=leetcode id=3403 lang=cpp
 *
 * [3403] Find the Lexicographically Largest String From the Box I
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lexiCmp(string a, string b) {
        // return
        // - -1: greater (a > b)
        // -  0: equal   (a = b)
        // -  1: smaller (a < b)
        int lenA = a.size(), lenB = b.size();
        for (int i = 0; i < min(lenA, lenB); i++) {
            if (a[i] < b[i]) {
                return 1;
            } else if (a[i] > b[i]) {
                return -1;
            }
        }
        if (lenA == lenB) {return 0;}
        return ((lenA - lenB) > 0) ? -1: 1;
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {return word;}
        int n = word.size(), maxLength = n - numFriends + 1; // maximum length of single split (other splits with length 1)
        string result = "";

        for (int i = 0; i < n; i++) {
            string substr = word.substr(i, min(n - i, maxLength));
            if (lexiCmp(result, substr) == 1 || result.empty()) {
                result = substr;
            }
        }

        return result;
    }
};
// @lc code=end

