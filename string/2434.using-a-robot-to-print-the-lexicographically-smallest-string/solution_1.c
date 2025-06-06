/*
 * @lc app=leetcode id=2434 lang=c
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

// @lc code=start
#include <string.h>

#define MAX_SIZE 100000

char lexiSmallest(int* cnt) {
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {return 'a' + i;}
    }
    return 'a';
}

char* robotWithString(char* s) {
    // The robot's string t works as a buffer stack
    // To output the lexicographically smallest string, only write character smaller than first character of string s 
    int n = strlen(s);

    int *count = malloc(26 * sizeof(int));  
    for (int i = 0; i < 26; i++) {count[i] = 0;}

    for (int i = 0; i < n; i++) {count[s[i]-'a']++;} 

    int tTop = -1, idx = 0;
    char t[MAX_SIZE];
    char *paper = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        t[++tTop] = s[i];
        count[s[i]-'a']--;

        while (tTop >= 0 && t[tTop] <= lexiSmallest(count)) { // Push smallest characters greedly
            paper[idx++] = t[tTop--];
        }
    }

    while (tTop >= 0) { // Pop all remaining characters and write on the paper
        paper[idx++] = t[tTop--];
    }

    paper[idx] = '\0'; // Null terminator
    return paper;
}
// @lc code=end

