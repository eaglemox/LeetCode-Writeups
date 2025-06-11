/*
 * @lc app=leetcode id=3445 lang=c
 *
 * [3445] Maximum Difference Between Even and Odd Frequency II
 */

// @lc code=start
#include <limits.h>
#define max(a, b) ((a > b) ? a : b)

int maxDifference(char* s, int k) {
    // s only consist of '0'~'4' (5 chars)
    int len = strlen(s), maxDiff = INT_MIN;

    for (char charA = '0'; charA <= '4'; charA++) {
        for (char charB = '0'; charB <= '4'; charB++) {
            if (charA == charB) {continue;} // Select two distinct character

            // Calculate prefix sum
            int sumA[len+1], sumB[len+1]; // Accumulate count before index
            sumA[0] = sumB[0] = 0;
            for (int i = 1; i <= len; i++) {
                sumA[i] = sumA[i-1] + (s[i-1] == charA);
                sumB[i] = sumB[i-1] + (s[i-1] == charB);
            }

            int buf[2][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    buf[i][j] = INT_MIN;
                }
            }

            // Sliding window difference: (sumA[j] - sumA[i]) - (sumB[j] - sumB[i]) = (sumA[j] - sumB[j]) + (sumB[i] - sumA[i])
            for (int i = 0, j = k; j <= len; j++) {
                for (; j - i >= k && sumA[j] > sumA[i] && sumB[j] > sumB[i]; i++) { // Length >= k and exist 'a' and 'b' in window
                    int pai = sumA[i] & 1, pbi = sumB[i] & 1;
                    buf[pai][pbi] = max(buf[pai][pbi], sumB[i] - sumA[i]);
                }
                
                // To make count of charA in window [i,j] odd, sumA[i] must have opposite parity of sumA[j], 
                // That is, we maximize the current difference (sumA[j] - sumB[j]) and previous difference (sumB[i] - sumA[i])
                int paj = sumA[j] & 1, pbj = sumB[j] & 1;
                if (buf[1-paj][pbj] > INT_MIN) { // Found before
                    maxDiff = max(maxDiff, sumA[j] - sumB[j] + buf[1-paj][pbj]);
                }
            }
        }
    }

    return maxDiff;
}
// @lc code=end

