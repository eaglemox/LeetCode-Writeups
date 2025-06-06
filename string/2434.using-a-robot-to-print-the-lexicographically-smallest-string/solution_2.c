/*
 * @lc app=leetcode id=2434 lang=c
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

// @lc code=start
#include <string.h>

#define MAX_SIZE 100001

char* robotWithString(char* s) {
    // The robot's string t works as a buffer stack
    // To output the lexicographically smallest string, only write character smaller than first character of string s 
    int n = strlen(s), tTop = -1, idx = 0;

    int count[26] = {};
    for (int i = 0; i < n; i++) {count[s[i]-'a']++;} 

    char smallest = 'a';
    static char t[MAX_SIZE], paper[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        t[++tTop] = s[i];
        count[s[i]-'a']--;
        while (smallest < 'z' && !count[smallest-'a']) {
            smallest++;
        }
        while (tTop >= 0 && t[tTop] <= smallest) {
            paper[idx++] = t[tTop--];
        }
    }

    paper[idx] = '\0'; // Null terminator
    return paper;
}
// @lc code=end

