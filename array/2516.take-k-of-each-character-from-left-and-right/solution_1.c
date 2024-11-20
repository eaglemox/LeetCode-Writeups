/*
 * @lc app=leetcode id=2516 lang=c
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

int takeCharacters(char* s, int k) {
    // Two pointer approach to track the indices of substring's start and end
    // Compare the upper bound and the taken count of the characters 
    // Time: O(N), Space: O(1)
    int length = strlen(s);
    int maxLength = 0;
    int count[3] = {0}, subCount[3] = {0};

    for (int i = 0; i < length; i++) {
        count[s[i]-'a']++;
    }
    // Impossible to take any character
    for (int i = 0; i < 3; i++) {
        if (count[i] < k) {return -1;}
        count[i] -= k; // upper bound frequency of substring
    }
    int i = 0, j = 0;
    while (j < length) {
        subCount[s[j]-'a']++;
        while (i <= j && (subCount[0] > count[0] ||
               subCount[1] > count[1] || subCount[2] > count[2])) {
            subCount[s[i++]-'a']--;
        }
        maxLength = max(maxLength, j - i + 1);
        j++;
    }
    return length - maxLength;
}
// @lc code=end

