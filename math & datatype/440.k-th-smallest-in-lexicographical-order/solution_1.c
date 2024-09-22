/*
 * @lc app=leetcode id=440 lang=c
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
#include <stdio.h>
#define min(a, b) ((a < b) ? a : b)
int countCombinations(long long n, long long prefix) {
    // count number of combinations of prefix within n
    int count = 0;
    long long lowerbound = prefix, upperbound = prefix + 1;
    while (lowerbound <= n) {
        // counting [prefix, prefix+1]
        // e.g. (103, 1) -> 10~19, 100~103
        count += min((n + 1), upperbound) - lowerbound;
        lowerbound *= 10;
        upperbound *= 10;
    }
    return count;
}
int findKthNumber(int n, int k) {
    // the value does not matter, count the number of digit combinations 
    int nextNum = 1; // always first number
    k--; // "1"

    while (k > 0) {
        int steps = countCombinations(n, nextNum);
        if (steps <= k) { // subtract possible combinations of current prefix
            k -= steps;
            nextNum++;
        } else { // enter next level of this digit
            nextNum *= 10;
            k--;
        }
    }
    return nextNum;
}
// @lc code=end

