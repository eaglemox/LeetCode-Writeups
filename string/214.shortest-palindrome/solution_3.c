/*
 * @lc app=leetcode id=214 lang=c
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverse(char* str) {
    int length = strlen(str);
    if (length == 0) {
        char *temp = malloc(sizeof(char));
        temp[0] = '\0';
        return temp;
    }
    char *reversed = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversed[length-1-i] = str[i];
    }
    reversed[length] = '\0';
    return reversed;
}
int* genNextTable(char* str) {
    // Find the longest prefix & suffix (LPS) of the pattern 
    int length = strlen(str);
    if (length == 0) {return NULL;}
    int *next = malloc(length * sizeof(int));
    next[0] = 0; // the only prefix, suffix is itself (str[0])
    for 
    return next;
}
char* shortestPalindrome(char* s) {
    // KMP algorithm: utilized to find the longest length of palindrome substring of s
    int length = strlen(s);
    if (length == 0) {return s;}
    
    char *reversed = reverse(s);
    char *combined = malloc((2 * length + 2) * sizeof(char));
    combined[0] = '\0';
    sprintf(combined, "%s#%s", s, reversed);
    int *nextTable = genNextTable(combined);
    int longestPalindromeLength = nextTable[strlen(combined) - 1];
    char *result;
    for (int i = 0; i < length; i++) {
        if (!memcmp(s, reversed+i, length-i)) {
            int appendLength = i;
            result = malloc((length + appendLength + 1) * sizeof(char));
            // reversed[0:i] substring
            strncpy(result, reversed, appendLength); // do not contain '\0'
            result[appendLength] = '\0';
            strcat(result, s);
            return result;
        }
    }
    // dummy return
    return s;
}
// @lc code=end

