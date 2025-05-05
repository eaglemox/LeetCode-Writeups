/*
 * @lc app=leetcode id=290 lang=c
 *
 * [290] Word Pattern
 */

// @lc code=start
bool wordPattern(char* pattern, char* s) {
    char map[26][500];
    char *p = strtok(s, " ");
    for (int i = 0; pattern[i]; i++) {
        int key = pattern[i] - 'a';
        if (map[key][0] && strcmp(map[key], p) || p == NULL) {
            // pattern doesn't match or word.length < pattern.length
            return false;
        } else {
            strcpy(map[key], p);
            // check if word bind to different pattern
            for (int j = 0; j < 26; j++) {
                if (key != j && strcmp(map[j], map[key]) == 0) {
                    return false;
                }
            }
        }
        p = strtok(NULL, " ");
    }

    return p ? false : true; // word.length > pattern.length
}
// @lc code=end

