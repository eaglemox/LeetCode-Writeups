/*
 * @lc app=leetcode id=2064 lang=c
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    // To minimized maxQuantity to k, the sum of each stores for product type with max k quantities must <= n
    // Find the max k that satisfies the constraint, Time: O(NlogM), Space: O(1), N: #stores, M: range of quantities
    int maxQuantity = 0;
    for (int i = 0; i < quantitiesSize; i++) {
        maxQuantity = max(maxQuantity, quantities[i]);
    }
    int i = 1, j = maxQuantity;
    while (i <= j) {
        int k = i + (j - i) / 2;
        // Compute requiredStores to satisfy max quantity k for each product
        int requiredStores = 0;
        for (int i = 0; i < quantitiesSize; i++) {
            requiredStores += quantities[i] / k;
            if (quantities[i] % k) {requiredStores++;}
        }
        if (requiredStores <= n) { // try lower k
            j = k - 1;
        } else { // k must be greater
            i = k + 1;
        }
    }
    
    return i;
}

// @lc code=end

