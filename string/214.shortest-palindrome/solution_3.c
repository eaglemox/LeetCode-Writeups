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
    int prevLen = 0; // record the previously found LPS length
    int *next = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {next[i] = 0;}
    next[0] = 0; // the only prefix, suffix is itself (str[0])
    for (int i = 1; i < length; ) { // until whole str is iterated
        // imaging sliding a pattern below the string
        // ababaca
        //   xxx
        //   ababaca
        if (str[i] == str[prevLen]) { // if prefix == suffix 
            prevLen++;
            next[i] = prevLen;
            i++;
        } else { // if not matched
            if (prevLen != 0) { // skip to the next char to re-match *move the pattern*
                prevLen = next[prevLen - 1];
            } else { // LPS length is zero, step forward
                next[i] = 0;
                i++;
            }
        }
    }
    // for (int i = 0; i < length; i++) {
    //     printf("%d ", next[i]);
    // } printf("\n");
    return next;
}
char* shortestPalindrome(char* s) {
    // KMP algorithm: utilized to find the longest length of palindrome substring of s
    int length = strlen(s);
    if (length == 0) {return s;}
    
    char *reversed = reverse(s);
    char *combined = malloc((2 * length + 2) * sizeof(char)); // add "#" and terminator
    combined[0] = '\0';

    sprintf(combined, "%s#%s", s, reversed); // concate string into "s#s'" form 

    int *nextTable = genNextTable(combined);
    int appendLength = length - nextTable[strlen(combined) - 1];

    char *result = malloc((length + appendLength + 1) * sizeof(char));
    strncpy(result, reversed, appendLength);
    result[appendLength] = '\0'; // set terminator
    strcat(result, s);
    
    free(reversed);
    free(combined);
    free(nextTable);

    return result;
}
// @lc code=end
