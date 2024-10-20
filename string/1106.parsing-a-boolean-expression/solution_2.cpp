/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        // Stack approach, Time: O(N), Space: O(N)
        stack<char> st;
        for (char exp : expression) {
            if (exp == '(' || exp == ',') {continue;}
            if (exp != ')') { // push non-')' expression
                st.push(exp);
            } else { // pop until operator
                bool containTrue = false, containFalse = false;
                while (st.top() != '&' && st.top() != '|' && st.top() != '!') {
                    char top = st.top();
                    st.pop();
                    if (top == 't') {containTrue = true;}
                    if (top == 'f') {containFalse = true;}
                }
                char op = st.top();
                st.pop();
                if (op == '&') {
                    st.push((containFalse) ? 'f' : 't');
                } else if (op == '|') {
                    st.push((containTrue) ? 't' : 'f');
                } else if (op == '!') {
                    st.push((containTrue) ? 'f' : 't');
                }
            }
        }
        return st.top() == 't';
    }
};
// @lc code=end

