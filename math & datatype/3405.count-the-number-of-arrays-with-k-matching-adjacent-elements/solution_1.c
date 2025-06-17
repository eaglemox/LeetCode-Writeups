/*
 * @lc app=leetcode id=3405 lang=c
 *
 * [3405] Count the Number of Arrays with K Matching Adjacent Elements
 */

// @lc code=start
#define MOD 1000000007
#define MAX 100000

long long fact[100000];
long long invfact[100000];

long long bpow(long long base, int p) {
    long long result = 1;
    while (p > 0) {
        if (p & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        p >>= 1;
    }

    return result;
}

long long C(int n, int k) {
    if (k > n || k < 0) {return 0;}
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int countGoodArrays(int n, int m, int k) {
    // This is a combinatorics problem.
    // In a "good" array of length n, there are (n - 1) adjacent pairs,
    // and exactly k of them must be equal (i.e., arr[i - 1] == arr[i]).
    // Step 1: Choose which k adjacent pairs are matched — this can be done in C(n - 1, k) ways.
    // Step 2: Fill in the array with numbers from [1, m].
    //         Since there are (n - k) distinct segments (i.e., maximal blocks of equal numbers),
    //         we assign the first segment in m ways, and each of the remaining (n - k - 1) segments in (m - 1) ways
    //         to avoid matching the previous value.
    if (!fact[0]) { // Precompute factorial and its multiplicative inverse 
        fact[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        // a^p-1 % p := 1 -> a^p-2 % p := a^-1 (p is prime)
        invfact[MAX-1] = bpow(fact[MAX-1], MOD - 2);
        for (int i = MAX - 1; i > 0; i--) {
            invfact[i-1] = (invfact[i] * i) % MOD;
        }
    }

    return C(n-1, k) * m % MOD * bpow(m - 1, n - k - 1) % MOD;
}
// @lc code=end

