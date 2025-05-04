/*
 * @lc app=leetcode id=1128 lang=c
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    // Possible dominoes configuration: 9*(9+1)/2 -> 45
    int count[46] = {0}, pairs = 0;
    for (int idx = 0; idx < dominoesSize; idx++) {
        int i = dominoes[idx][0], j = dominoes[idx][1];
        if (i > j) {swap(&i, &j);} // make i <= j
        int index = j - i + 1;
        if (i > 1) {
            index += (20 - i) * (i - 1) / 2; // (9 + 11 - i)
        }
        count[index]++;
    }
    for (int i = 1; i <= 45; i++) {
        pairs += count[i] * (count[i] - 1) / 2;
    }
    return pairs;
}
// @lc code=end

