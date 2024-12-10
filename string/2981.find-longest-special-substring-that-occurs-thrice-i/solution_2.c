/*
 * @lc app=leetcode id=2981 lang=c
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int maximumLength(char* s) {
    // Track 3 longest length of substring of same consecutive letter
    // Compute the possible max length of special substring that occur thrice
    // Time: O(N), Space: O(26)
    int len = strlen(s), sublen = 0;
    int count[26], lengthCount[26][4]; // 4-th spare count for swapping
    memset(count, 0, sizeof(count));
    memset(lengthCount, 0, sizeof(lengthCount));
    for (int i = 0; i < len; i++) {
        sublen++;
        // Reach end or different letter
        if (i + 1 == len || s[i] != s[i+1]) {
            int c = s[i] - 'a';
            lengthCount[c][count[c]++] = sublen;
            for (int j = 3; j > 0; j--) {
                if (lengthCount[c][j-1] < lengthCount[c][j]) {
                    int temp = lengthCount[c][j-1];
                    lengthCount[c][j-1] = lengthCount[c][j];
                    lengthCount[c][j] = temp;
                }
            }
            if (count[c] > 3) {count[c] = 3;}
            sublen = 0; // reset length
        }
    }
    int result = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && lengthCount[i][0] > 2) {
            result = max(result, lengthCount[i][0] - 2);
        }
        if (count[i] > 1 && lengthCount[i][0] > 1) {
            result = max(result, min(lengthCount[i][0] - 1, lengthCount[i][1]));
        }
        if (count[i] > 2) {
            result = max(result, lengthCount[i][2]);
        }
    }
    return result;
}
// @lc code=end

