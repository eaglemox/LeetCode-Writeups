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
    // To find part is already palindrome (from start bc. only adding characters at front of string) 
    // then complete it into whole palindrome
    int length = strlen(s);
    if (length == 0) {return s;}
    
    int r;
    int isPalindrome = 0;
    for (r = length - 1; r >= 0; r--) {
        int _l = 0, _r = r;
        isPalindrome = (s[_l] == s[_r]);
        while (isPalindrome && (_l < _r)) {
            isPalindrome = (s[++_l] == s[--_r]);
        }
        if (isPalindrome) {break;}
    }

    int rightLength = length - (r + 1);
    char *rightPart = malloc((rightLength+1) * sizeof(char)); // terminator
    rightPart[0] = '\0';
    strncpy(rightPart, s + (r + 1), rightLength+1);
    
    char *temp = malloc((length + rightLength + 1) * sizeof(char));
    temp[0] = '\0';

    strcat(temp, reverse(rightPart));
    free(rightPart);
    strcat(temp, s);
    
    return temp;
}
// @lc code=end

