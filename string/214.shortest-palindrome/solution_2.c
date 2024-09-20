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
char* shortestPalindrome(char* s) {
    // Matching with reversed string
    int length = strlen(s);
    if (length == 0) {return s;}
    
    char *reversed = reverse(s);
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

