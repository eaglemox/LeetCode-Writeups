/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <stdio.h>
#include <limits.h>
int myAtoi(char *s)
{
    int buffer, result = 0;
    int sign = 1;
    int signRead = 0;
    int numberRead = 0;
    for (int i = 0; s[i] != NULL; i++) {
        if (s[i] >= '0' && s[i] <= '9') { // digit
            numberRead = 1;
            buffer = s[i] - '0';
            // round to int range [-2^31, 2^31 - 1]
            // **result's upper limit is 2^31 - 1, while s may be -2^31**
            if (sign == 1) {
                if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && buffer >= 7)) {
                    return INT_MAX;
                }
            } else if (sign == -1) {
                if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && buffer >= 8)) {
                    return INT_MIN;
                }
            }
            result = result * 10 + buffer;
        }
        else { // symbol (non-digit)
            if (!numberRead) {
                // ignore leading white space
                if (s[i] == ' ' && !signRead) {continue;}
                else if (s[i] == '+' || s[i] == '-') {
                    if (signRead) {return 0;}
                    sign = (s[i] == '+') ? 1 : -1;
                    signRead = 1;
                } else {
                    return 0;
                }
            } else { // number read, output currrent result
                break;
            }
        }
    }
    return sign * result;
}
// @lc code=end
