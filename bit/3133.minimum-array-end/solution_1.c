/*
 * @lc app=leetcode id=3133 lang=c
 *
 * [3133] Minimum Array End
 */

// @lc code=start
long long minEnd(int n, int x) {
    // Increasing int array, that the AND of the array is x
    // Return the minimum of last number, that is x with additional log2(n - 1) bits set
    // Time: O(logn), Space: O(1)
    long long result = x;
    // printBits(result);

    int mask = n - 1; // the order of clear bit to be set 
    for (int i = 0; i < 64 && mask > 0; i++) {
        long long bit = 1LL << i;
        if (!(result & bit)) {
            result |= (mask & 1) ? bit : 0;
            mask >>= 1;
        }
    }
    // printBits(result);
    return result;
}

void printBits(long long num) {
    int bits = 0;
    while ((1LL << bits) <= num) {
        bits++;
    }
    printf("%lld: ", num);
    while (bits > 0) {
        printf("%d", (num >> (bits - 1)) & 1);
        bits--;
    } printf("\n");
}
// @lc code=end