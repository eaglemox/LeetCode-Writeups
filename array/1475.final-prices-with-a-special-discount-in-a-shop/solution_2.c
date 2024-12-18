/*
 * @lc app=leetcode id=1475 lang=c
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 500

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    // Monotonic stack, maintain its monotonic increasing increasing.
    // Pop to discount the prices
    // Time: O(N), Space: O(N)
    int stack[MAX_SIZE] = {0}, top = -1;
    for (int i = 0; i < pricesSize; i++) {
        while (top != -1 && prices[stack[top]] >= prices[i]) {
            prices[stack[top]] -= prices[i];
            top--;
        }
        stack[++top] = i;
    }
    *returnSize = pricesSize;
    return prices;
}
// @lc code=end

