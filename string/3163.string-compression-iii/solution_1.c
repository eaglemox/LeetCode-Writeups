/*
 * @lc app=leetcode id=3163 lang=c
 *
 * [3163] String Compression III
 */

// @lc code=start
#include <string.h>

char* compressedString(char* word) {
    // Time: O(N), Space: O(N)
    int len = strlen(word), index = 0;
    char *comp = malloc((2 * len + 1) * sizeof(char)); // max possible length 400001
    for (int i = 0; i < len;) {
        int count = 1;
        char prev = word[i++];
        while (count < 9 && i < len && word[i] == prev) {
            count++;
            i++;
        }
        // append prefix and character
        comp[index++] = count + '0';
        comp[index++] = prev;
    }
    comp[index] = '\0'; // null terminator
    return comp;
}
// @lc code=end

