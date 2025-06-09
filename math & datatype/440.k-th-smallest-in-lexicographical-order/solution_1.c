/*
 * @lc app=leetcode id=440 lang=c
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
#define min(a, b) ((a < b) ? a : b)

int branchSize(int n, int curr, int next) {
    int size = 0;
    while (curr <= n) {
        size += min(n + 1, next) - curr; // Count number of nodes between curr and next (but no more than n)
        curr *= 10;
        next *= 10;
    }

    return size;
}

int findKthNumber(int n, int k) {
    // Precompute subtree sizes in the trie to skip branches when locating the k-th number.
    int curr = 1;
    k--; // 1 is always first number

    while (k > 0) {
        // If k-th number is not in this branch, skip to next branch, else dive deeper into the subtree
        int numNodes = branchSize(n, curr, curr + 1);
        if (numNodes <= k) {
            curr++;
            k -= numNodes;
        } else {
            curr *= 10;
            k--;
        }
    }

    return curr;
}
// @lc code=end

