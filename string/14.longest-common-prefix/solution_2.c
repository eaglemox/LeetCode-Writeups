/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) {return strs[0];}
    // initialization
    int prefixLen = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0; int currentLen = strlen(strs[i]);
        // find maximum common prefix length of str[0] and str[i].. 
        while(j < currentLen && strs[0][j] == strs[i][j]) {j++;}
        prefixLen = (prefixLen >= j) ? j : prefixLen;
    }
    // proper way to return
    // char *prefix = malloc((prefixLen + 1) * sizeof(char));
    // prefix[prefixLen] = '\0';
    // memmove(prefix, strs[0], prefixLen);
    // return prefix;
    
    // this is so fucked up
    strs[0][prefixLen] = '\0';
    return strs[0];
}
// @lc code=end

