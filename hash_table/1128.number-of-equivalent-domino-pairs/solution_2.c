/*
 * @lc app=leetcode id=1128 lang=c
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    // Sum the pairs using addition at each iteration instead of multiplication at the end
    // Convert domino configurations into independent keys
    int count[100] = {0}, pairs = 0;
    for (int idx = 0; idx < dominoesSize; idx++) {
        int i = dominoes[idx][0], j = dominoes[idx][1];
        int index = (i < j) ? i * 10 + j : j * 10 + i;
        pairs += count[index]++;
    }
    return pairs;
}
// @lc code=end

