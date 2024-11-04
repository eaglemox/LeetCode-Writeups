/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
#include <limits.h>
#include <stdbool.h>

char* toHex(int num) {
    // Time: O(1), Space: O(1)
    if (num == 0) {return "0";}
    // absolute of INT_MIN cannot be represented in int range 
    if (num == INT_MIN) {return "80000000";}
    bool isNegative = num < 0;
    num = isNegative ? -num : num;
    int len = 1;
    if (isNegative) {
        len = 8;
    } else {
        while (len < 8 && 1 << (4 * len) <= num) {len++;}
    }
    char *result = malloc((len + 1) * sizeof(char));

    // Two's complement
    for (int i = len - 1; i >= 0; i--) {
        // replace with its complement hex value (e.g. 0 -> f, 2 -> d)
        int res = (isNegative) ? (15 - (num % 16)) : (num % 16);
        result[i] = (res > 9) ? ('a' + res - 10) : ('0' + res);
        num >>= 4;
    }
    if (isNegative) { // add one to LSB
        if (result[len-1] == 'f') {
            int carryIndex = len - 1;
            while (carryIndex > 0 && result[carryIndex] == 'f') {
                result[carryIndex] = '0';
                carryIndex--;
            }
            result[carryIndex] = (result[carryIndex] == '9') ? 'a' : (result[carryIndex] + 1);
        } else if (result[len-1] == '9') {
            result[len-1] = 'a';
        } else {
            result[len-1] = result[len-1] + 1;
        }
    }
    result[len] = '\0';
    
    return result;
}
// @lc code=end

