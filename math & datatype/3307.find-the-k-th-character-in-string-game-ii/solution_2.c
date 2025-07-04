/*
 * @lc app=leetcode id=3307 lang=c
 *
 * [3307] Find the K-th Character in String Game II
 */

// @lc code=start
char kthCharacter(long long k, int* operations, int operationsSize) {
    // Tracking how many shift have made
    // word[k] is result from performing operation to word[k-k's highest bit]
    // e.g. k = 10 (0b1010), word[10] <- word[2] (0b0010)
    int result = 0, hb;
    while (k != 1) {
        hb = 63 - __builtin_clzll(k);

        // k is power of 2 minus half of k (e.g. word[8] = word[4])
        if ((1LL << hb) == k) {hb--;}
        k -= (1LL << hb);

        // If is the shift copy operation, increment result
        if (operations[hb]) {
            result++;
        }
    }

    return 'a' + (result % 26);
}
// @lc code=end

