/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max heap approach, Time: O(a+b+c), Space: O(1)
        string happyString;
        priority_queue<pair<int,char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            int len = happyString.size();
            auto [count, letter] = pq.top();
            pq.pop();
            // string already has 2 consecutive letters
            if (len >= 2 && (happyString[len-1] == letter && happyString[len-2] == letter)) {
                if (pq.empty()) {break;}
                auto [nextCount, nextLetter] = pq.top();
                pq.pop();
                happyString += nextLetter;
                if (nextCount > 1) {
                    pq.push({nextCount - 1, nextLetter});
                }
            } else { // add letter with max count
                happyString += letter;
                count--;
            }
            if (count > 0) {
                pq.push({count, letter});
            }
            // cout << happyString << endl;
        }
        return happyString;
    }
};
// @lc code=end

