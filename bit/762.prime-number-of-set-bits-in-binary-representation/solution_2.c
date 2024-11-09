/*
 * @lc app=leetcode id=762 lang=c
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
#include <stdbool.h>

bool isPrime(int num) {
    if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 ||
        num == 13 || num == 17 || num == 19) {
        return true;
    }
    return false;
}

int countPrimeSetBits(int left, int right) {
    // Count of number with prime set bits in the range [left, right]
    // right is within 20 bits, possible primes: [2,3,5,7,11,13,17,19]
    // Time: O(N), Space: O(1), N: right - left + 1
    int result = 0;
    // whether number of the position is prime
    // int primeMask = 0b10100010100010101100;
    for (int i = left; i <= right; i++) {
        int setBits = 0, tmp = i;
        while (tmp > 0) {
            setBits += tmp & 1;
            tmp >>= 1;
        }
        if (isPrime(setBits)) {
            result++;
        }
    }
    return result;
}
// @lc code=end
