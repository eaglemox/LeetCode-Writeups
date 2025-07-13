/*
 * @lc app=leetcode id=2410 lang=c
 *
 * [2410] Maximum Matching of Players With Trainers
 */

// @lc code=start
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    // Sort players and trainers array then iterate trainers to 
    // find the player with lowest ability within the training capacity 
    // players:  [4, 7, 9]
    // trainers: [2, 5, 8, 8]
    // 2 < 4 -> skip to next trainer
    // 5 > 4 -> match
    // 8 > 7 -> match
    // 8 < 9 -> skip to next trainer (end)

    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);

    int result = 0;
    for (int i = 0, j = 0; i < playersSize && j < trainersSize; j++) {
        if (players[i] <= trainers[j]) {
            i++;
            result++;
        }
    }

    return result;
}
// @lc code=end

