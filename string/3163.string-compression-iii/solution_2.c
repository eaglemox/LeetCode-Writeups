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
        while (i < len && word[i] == prev) { // read more than 9 characters
            count++;
            i++;
        }
        // append prefix and character
        if (count <= 9) {
            comp[index++] = count + '0';
            comp[index++] = prev;
        } else { // more than 9
            while (count > 9) {
                comp[index++] = '9';
                comp[index++] = prev;
                count -= 9;
            } 
            if (count > 0) {
                comp[index++] = count + '0';
                comp[index++] = prev;
            }
        }
    }
    comp[index] = '\0'; // null terminator
    return comp;
}
// @lc code=end

