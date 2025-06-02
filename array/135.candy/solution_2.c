/*
 * @lc app=leetcode id=135 lang=c
 *
 * [135] Candy
 */

// @lc code=start
int candy(int* ratings, int ratingsSize) {
    // One pass approach
    int result = 1; // 0-th child
    int up = 0, down = 0, peak = 0;

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1]) {
            down = 0;
            peak = ++up;
            result += 1 + up;
        } else if (ratings[i] < ratings[i-1]) {
            up = 0;
            down++;
            // Check if we need more candies at peak
            result += down + !(peak >= down); // 1 - (peak >= down)
        } else {
            up = down = peak = 0;
            result += 1;
        }
    }

    return result;
}
// @lc code=end

