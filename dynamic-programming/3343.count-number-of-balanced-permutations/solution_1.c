/*
 * @lc app=leetcode id=3343 lang=c
 *
 * [3343] Count Number of Balanced Permutations
 */

// @lc code=start
#include <string.h>

#define MOD 1000000007
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int countBalancedPermutations(char* num) {
    // For num with length N, there are N! permutations -> max 80!
    // We cannot simply list all permutations then count balanced ones
    // Using DP to find possible combinations that both odd and even digits sum up to totalSum/2
    int len = strlen(num), sum = 0, count[10] = {0};
    for (int i = 0; i < len; i++) {
        count[num[i]-'0']++;
        sum += num[i] - '0';
    }
    if (sum & 1) { // Sum of digits cannot be equally divided
        return 0;
    }

    int target = sum / 2;
    int maxOdd = (len + 1) / 2;

    // Precompute the C(n, k) matrix (Pascal's triangle)
    long long comb[maxOdd+1][maxOdd+1];
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= maxOdd; i++) {
        comb[i][i] = comb[i][0] = 1; // choose none/all
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }

    // dp[i][j]: permutations which j odd digits sum up to i
    long long dp[target+1][maxOdd+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // base case

    int digitsCount = 0, digitsSum = 0;
    for (int i = 0; i <= 9; i++) { // Find valid permutations digit by digit
        digitsCount += count[i];
        digitsSum += i * count[i];
        
        for (int oddCount = min(digitsCount, maxOdd);
             oddCount >= max(0, digitsCount - (len - maxOdd));
             oddCount--) { // number of digits filled the odd position
            int evenCount = digitsCount - oddCount;
            
            for (int currentSum = min(digitsSum, target);
                 currentSum >= max(0, digitsSum - target); currentSum--) {
                long long ways = 0;
                
                for (int j = max(0, count[i] - evenCount);
                     j <= min(count[i], oddCount); j++) { // number of digits i placed in odd position
                    if (i * j > currentSum) {continue;}
                    long long prevWays = dp[currentSum - i * j][oddCount - j];
                    ways += prevWays * comb[oddCount][j] % MOD * comb[evenCount][count[i] - j] % MOD;
                }
                dp[currentSum][oddCount] = ways % MOD;
            }
        }
    }
    return dp[target][maxOdd];
}
// @lc code=end

