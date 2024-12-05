/*
 * @lc app=leetcode id=2337 lang=c
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool canChange(char* start, char* target) {
    // Two pointer check the order of chars
    // Time: O(N), Space: O(1)
    int i = 0, j = 0, length = strlen(start);
    while (i < length && j < length) {
        while (start[i] == '_') {i++;}
        while (target[j] == '_') {j++;}
        if (i == length || j == length) {break;}
        if (start[i] != target[j]) {return false;}
        if ((start[i] == 'L' && i >= j) || (start[i] == 'R' && i <= j)) {i++; j++;}
        else {return false;}
    }
    while (start[i] == '_') {i++;} // move to last char
    while (target[j] == '_') {j++;} // move to last char
    return (i == j && i == length); // all chars are checked
}
// @lc code=end

