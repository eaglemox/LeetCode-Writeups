/*
 * @lc app=leetcode id=2601 lang=c
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start
#include <stdbool.h>

bool primeSubOperation(int* nums, int numsSize) {
    int primes[1001];
    bool isPrime[1001];
    int primeSize = 0;
    for (int i = 0; i <= 1000; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i <= 1000; i++) {
        if (isPrime[i]) {
            primes[primeSize++] = i;
            for (int j = i * i; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }
    primes[primeSize] = 1000; // max value

    for (int i = 0; i < numsSize; i++) {
        int diff = (i > 0) ? nums[i] - nums[i-1] : nums[0];
        if (diff <= 0) {return false;}
        // Find largest prime to substract
        int j = -1;
        while (j < primeSize && primes[j+1] < diff) {
            j++;
        }
        nums[i] -= (j != -1) ? primes[j] : 0;
    }
    return true;
}
// @lc code=end

