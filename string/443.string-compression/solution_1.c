/*
 * @lc app=leetcode id=443 lang=c
 *
 * [443] String Compression
 */

// @lc code=start
#include <string.h>

int compress(char* chars, int charsSize) {
    // Utilize sprintf() to convert int into string
    // Time: O(N), Space: O(1)
    int length = 0;
    char buffer[6]; // length max 2000
    for (int i = 0; i < charsSize; i++) {
        int count = 1;
        // Move to end of consecutive characters
        while ((i + 1) < charsSize && chars[i+1] == chars[i]) {
            count++;
            i++;
        }

        chars[length++] = chars[i];
        
        if (count > 1) {
            int len = sprintf(buffer, "%d", count);
            for (int j = 0; j < len; j++) {
                chars[length++] = buffer[j];
            }
        }
    }
    // original string do not have '\0' terminator
    return length;
}
// @lc code=end

