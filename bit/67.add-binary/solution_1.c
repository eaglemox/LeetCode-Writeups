/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#define MAX_LEN 10001 // max: 2*10^4
char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLength = (lenA > lenB) ? lenA + 1 : lenB + 1; // carry over: 1 bit
    
    char *sum = malloc((maxLength + 1) * sizeof(char)); // terminator: 1 bit
    sum[maxLength] = '\0';
    sum[0] = '*'; // carry over placeholder

    // add from tail
    int carry = 0;
    int bitA, bitB;
    int i = lenA - 1, j = lenB - 1, k = maxLength - 1;
    while (i >= 0 || j >= 0 || carry) {
        bitA = (i >= 0) ? (a[i--] - '0') : 0;
        bitB = (j >= 0) ? (b[j--] - '0') : 0;
        // char  <-      (int) -- convert to char
        sum[k--] = (bitA ^ bitB ^ carry) + '0';
        carry = (bitA & bitB) | (carry & (bitA ^ bitB));
    }
    if (sum[0] == '*') { // no carry over at (maxLength+1)-th digit
        memmove(sum, sum + 1, maxLength);
    }

    return sum;
}
// @lc code=end

