/*
 * @lc app=leetcode id=2337 lang=c
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool canChange(char* start, char* target) {
    // Two pointer check the order of chars, modify the while loop range
    // check if start and target reach thier last char
    // Time: O(N), Space: O(1)
    int i = 0, j = 0, length = strlen(start);
    while (i <= length && j <= length) {
        while (start[i] == '_') {i++;}
        while (target[j] == '_') {j++;}
        if (i == length || j == length) {
            return (i == length && j == length);
        }
        if (start[i] != target[j]) {return false;}
        if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {return false;}
        else {i++; j++;}
    }
    return true;
}
// @lc code=end

