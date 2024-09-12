/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) {return strs[0];}

    int charIndex = 0;
    int strEnd = 0;
    char buffer;
    char *prefix = malloc(201 * sizeof(char));

    while (!strEnd) {
        buffer = strs[0][charIndex];
        if (buffer == '\0') {break;}
        // printf("buffer: %c\n", buffer);
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][charIndex] == '\0') {strEnd = 1;}
            if (strs[i][charIndex] != buffer) {
                prefix[charIndex] = '\0';
                return prefix;
            }
            // printf("%d-th character of str[%d]: %c\n", charIndex, i, strs[i][charIndex]);
        }
        prefix[charIndex] = buffer;
        charIndex++;
    }
    if (charIndex == 0) {return "";}
    prefix[charIndex] = '\0'; // terminator
    
    return prefix;
}
// @lc code=end

