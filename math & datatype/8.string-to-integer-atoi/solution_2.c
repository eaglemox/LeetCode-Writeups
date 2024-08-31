/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <stdio.h>
#include <limits.h>
int myAtoi(char* s) {
    int buffer, result = 0;
    int sign = 1;
    int index = 0;
    // ignore leading white space
    while (s[index] == ' ') {index++;}
    if (s[index] == '+' || s[index] == '-') {
        sign = (s[index] == '+') ? 1 : -1;
        index++;
    }
    while (s[index] >= '0' && s[index] <= '9') {
        buffer = s[index] - '0';
        // round to int range [-2^31, 2^31 - 1]
        if (sign == 1) {
            if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && buffer >= 7)) {
                return INT_MAX;
            }
        }
        else if (sign == -1) {
            if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && buffer >= 8)) {
                return INT_MIN;
            }
        }
        result = result * 10 + buffer;
        printf("read integer %d, %d\n", buffer, result);
        index++;
    }
    return sign * result;
}
// @lc code=end

