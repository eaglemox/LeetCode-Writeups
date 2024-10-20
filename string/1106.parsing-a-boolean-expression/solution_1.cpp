/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        // Recursive parsing, Time: O(N), Space: O(N)
        int index = 0;
        return parseExpr(expression, index);
    }
private:
    bool parseExpr(string& expr, int& index) {
        // the index should be reference <- no backtracking
        char currExpr = expr[index++];
        // base case
        if (currExpr == 't') {return true;}
        if (currExpr == 'f') {return false;}
        if (currExpr == '!') {
            index++; // skip '('
            bool val = parseExpr(expr, index);
            index++; // skip ')'
            return !val;
        }

        vector<bool> expressions;
        index++; // skip '('
        while (expr[index] != ')') {
            if (expr[index] != ',') {
                expressions.push_back(parseExpr(expr, index));
            } else {
                index++;
            }
        }
        index++; // skip ')'

        if (currExpr == '&') {
            for (bool e : expressions) {
                if (!e) {return false;}
            }
            return true;
        }
        if (currExpr == '|') {
            for (bool e : expressions) {
                if (e) {return true;}
            }
            return false;
        }

        return false;
    }
};
// @lc code=end

