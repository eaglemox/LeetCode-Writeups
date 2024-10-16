/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Greedy approach, Time: O(a+b+c), Space: O(1)
        string happyString;
        char prev;
        while (a > 0 || b > 0 || c > 0) {
            //printf("%d %d %d\n", a, b, c);
            if (a >= b && a >= c) { // a max, or a >= b, c
                if (prev == 'a') {
                    if (b > 0 && b >= c) {
                        happyString += 'b';
                        prev = 'x'; // reset count
                        b--;
                    } else if (c > 0) {
                        happyString += 'c';
                        prev = 'x';
                        c--;
                    } else {break;} // cannot add any letter except for 'a'
                } else { // add max to 2 'a'
                    int count = 0;
                    while (a > 0 && count < 2) {
                        happyString += 'a';
                        a--;
                        count++;
                    }
                    if (count == 2) {prev = 'a';}
                    else {prev = 'x';}
                }
            } else if (b > a && b >= c) { // b max, or b = c
                if (prev == 'b') {
                    if (a > 0 && a >= c) {
                        happyString += 'a';
                        prev = 'x';
                        a--;
                    } else if (c > 0) {
                        happyString += 'c';
                        prev = 'x';
                        c--;
                    } else {break;}
                } else {
                    int count = 0;
                    while (b > 0 && count < 2) {
                        happyString += 'b';
                        b--;
                        count++;
                    }
                    if (count == 2) {prev = 'b';}
                    else {prev = 'x';}
                }
            } else if (c > a && c > b) { // c max
                if (prev == 'c') {
                    if (a > 0 && a >= b) {
                        happyString += 'a';
                        prev = 'x';
                        a--;
                    } else if (b > 0) {
                        happyString += 'b';
                        prev = 'x';
                        b--;
                    } else {break;}
                } else {
                    int count = 0;
                    while (c > 0 && count < 2) {
                        happyString += 'c';
                        c--;
                        count++;
                    }
                    if (count == 2) {prev = 'c';}
                    else {prev = 'x';}
                }
            }
        }
        return happyString;
    }
};
// @lc code=end

