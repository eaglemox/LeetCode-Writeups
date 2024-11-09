/*
 * @lc app=leetcode id=762 lang=c
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
int countPrimeSetBits(int left, int right) {
    // Count of number with prime set bits in the range [left, right]
    // right is within 20 bits, possible primes: [2,3,5,7,11,13,17,19]
    // Time: O(N), Space: O(1), N: right - left + 1
    int result = 0;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (int i = left; i <= right; i++) {
        int setBits = countBits(i);
        for (int j = 0; j < 8; j++) {
            if (setBits == primes[j]) {result++;}
        }
    }
    return result;
}

int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
// @lc code=end

