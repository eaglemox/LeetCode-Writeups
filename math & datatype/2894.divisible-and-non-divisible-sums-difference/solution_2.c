/*
 * @lc app=leetcode id=2894 lang=c
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
int differenceOfSums(int n, int m) {
    // num1: sum(1,n) - num2 = ((n + 1) * n / 2) - num2
    // num2: 1m + 2m + 3m + ... + km (km <= n) = (k + 1) * m * k / 2, k = n // m (integer division, round to floor)
    // num1 - num2 = (n + 1) * n / 2 - 2 * ((n / m) + 1) * m * (n / m) / 2
    //               (n + 1) * n / 2 - ((n / m) + 1) * n
    return ((n + 1) * n / 2) - ((n / m) + 1) * m * (n / m);
}
// @lc code=end

