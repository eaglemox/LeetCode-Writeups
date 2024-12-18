/*
 * @lc app=leetcode id=1475 lang=c
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    // Brute force checking each price's next lower price
    // Time: O(N^2), Space: O(1)
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                prices[i] -= prices[j];
                break;
            }
        }
    }
    *returnSize = pricesSize;
    return prices;
}
// @lc code=end

