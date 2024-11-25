/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <string.h>

int romanSymbolValue (char symbol) {
    switch (symbol) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return -1;
}

int romanToInt(char* s) {
    // Helper function to convert symbol into int, then compute result by roman numeral rules
    // Time: O(N), Space: O(1)
    int len = strlen(s), result = romanSymbolValue(s[len-1]);
    for (int i = len - 2; i >= 0; i--) {
        if (romanSymbolValue(s[i]) < romanSymbolValue(s[i+1])) {
            result -= romanSymbolValue(s[i]); // ascending symbols -> right - left
        } else {
            result += romanSymbolValue(s[i]); // descending symbols -> left + right
        }
    }
    return result;
}
// @lc code=end

