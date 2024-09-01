/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <limits.h>
int divide(int dividend, int divisor) {
    // multiplication, division, and mod operators are prohibited
    if (dividend == divisor) {return 1;}
    int sameSign = (dividend < 0 == divisor < 0);
    unsigned int quotient = 0;
    // prevent overflow
    unsigned int a = (dividend == INT_MIN) ? (unsigned int)INT_MAX + 1 : abs(dividend);
    unsigned int b = (divisor == INT_MIN) ? (unsigned int)INT_MAX + 1 : abs(divisor);
    while (a >= b) {
        int shift = 0; // shift bits
        if (b < INT_MAX) { // prevent unsigned int overflow 2^31<<1 = 2^32 > (2^32 - 1)
            // find maximun divisor: 2^n*b
            while (a > (b<<shift + 1)) {
                shift++;
            }
        }
        printf("divide %u with %u\n", a, b<<shift);
        a = a - (b<<shift);
        quotient += (1<<shift); // quotion add 2^n
        printf("current q= %u\n", quotient);
    }
    if (quotient == (1U<<31) && sameSign) {
        return INT_MAX;
    }
    return sameSign ? quotient: -quotient;
}
// @lc code=end

