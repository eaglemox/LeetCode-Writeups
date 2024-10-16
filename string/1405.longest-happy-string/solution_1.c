/*
 * @lc app=leetcode id=1405 lang=c
 *
 * [1405] Longest Happy String
 */

// @lc code=start
#include <string.h>

char* longestDiverseString(int a, int b, int c) {
    // max length a+b+c
    char *happyString = malloc((a + b + c + 1) * sizeof(char));
    int currIndex = 0;
    char prev;
    while (a > 0 || b > 0 || c > 0) {
        if (a >= b && a >= c) {
            if (prev == 'a') {
                if (b > 0 && b >= c) {
                    happyString[currIndex++] = 'b';
                    prev = 'x';
                    b--;
                } else if (c > 0) {
                    happyString[currIndex++] = 'c';
                    prev = 'x';
                    c--;
                } else {break;}
            } else {
                int count;
                for (count = 0; a > 0 && count < 2; a--, count++) {
                    happyString[currIndex++] = 'a';
                }
                if (count == 2) {prev = 'a';}
                else {prev = 'x';}
            }
        } else if (b > a && b >= c) {
            if (prev == 'b') {
                if (a > 0 && a >= c) {
                    happyString[currIndex++] = 'a';
                    prev = 'x';
                    a--;
                } else if (c > 0) {
                    happyString[currIndex++] = 'c';
                    prev = 'x';
                    c--;
                } else {break;}
            } else {
                int count;
                for (count = 0; b > 0 && count < 2; b--, count++) {
                    happyString[currIndex++] = 'b';
                }
                if (count == 2) {prev = 'b';}
                else {prev = 'x';}
            }
        } else if (c > a && c > b) {
            if (prev == 'c') {
                if (a > 0 && a >= b) {
                    happyString[currIndex++] = 'a';
                    prev = 'x';
                    a--;
                } else if (b > 0) {
                    happyString[currIndex++] = 'b';
                    prev = 'x';
                    b--;
                } else {break;}
            } else {
                int count;
                for (count = 0; c > 0 && count < 2; c--, count++) {
                    happyString[currIndex++] = 'c';
                }
                if (count == 2) {prev = 'c';}
                else {prev = 'x';}
            }
        }
        //happyString[currIndex] = '\0';
        //printf("%s\n", happyString);
    }
    happyString[currIndex] = '\0';
    return happyString;
}
// @lc code=end

