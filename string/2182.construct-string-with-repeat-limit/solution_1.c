/*
 * @lc app=leetcode id=2182 lang=c
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

char* repeatLimitedString(char* s, int repeatLimit) {
    // Count the appearance of each character, then reconstruct the string
    // If reach repeat limit append second largest character instead
    // Time: O(26*N), Space: O(26)
    int len = strlen(s), largest = 0, count[26] = {0};
    for (int i = 0; i < len; i++) {
        largest = max(largest, s[i] - 'a');
        count[s[i]-'a']++;
    }
    char *result = malloc((len + 1) * sizeof(char));
    int index = 0, repeat = 0;
    while (index < len) {
        // Find next largest character
        while (count[largest] == 0) {
            largest--;
            repeat = 0;
        }
        // Append characters until the limit is reached
        while (repeat < repeatLimit && count[largest]) {
            result[index++] = largest + 'a';
            count[largest]--;
            repeat++;
        }
        if (repeat >= repeatLimit && count[largest]) {
            int secondLargest = largest - 1;
            while (secondLargest >= 0 && count[secondLargest] == 0) {secondLargest--;}
            if (secondLargest < 0) {break;} // Can't find available secondLargest
            // Different character appended therefore reset repeat count
            result[index++] = secondLargest + 'a';
            count[secondLargest]--;
            repeat = 0;
        }
    }
    result[index] = '\0'; // end terminator
    return result;
}
// @lc code=end

