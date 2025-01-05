/*
 * @lc app=leetcode id=2381 lang=c
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
#include <string.h>

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    // After compute the shift difference of each character, apply to the string s
    // Time: O(M+N), Space: O(N), N: len(s), M: shiftsSize
    int len = strlen(s), shiftDiff[len+1]; // Reserve 1 more space for shifts at last index
    memset(shiftDiff, 0, sizeof(shiftDiff));
    for (int i = 0; i < shiftsSize; i++) {
        int start = shifts[i][0], end = shifts[i][1], dir = shifts[i][2];
        shiftDiff[start] += (dir == 1) ? 1 : -1;
        shiftDiff[end+1] += (dir == 1) ? -1 : 1; // The range is inclusive
    }
    for (int i = 0, shift = 0; i < len; i++) {
        shift += shiftDiff[i];
        s[i] = (((s[i] - 'a' + shift) % 26) + 26) % 26 + 'a';
    }
    return s;
}
// @lc code=end

