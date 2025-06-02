/*
 * @lc app=leetcode id=135 lang=c
 *
 * [135] Candy
 */

// @lc code=start
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)

int candy(int* ratings, int ratingsSize) {
    // Two pass approach
    int *candies = malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }

    int result = 0;
    for (int i = 0; i < ratingsSize; i++) {
        result += candies[i];
    }

    return result;
}
// @lc code=end

