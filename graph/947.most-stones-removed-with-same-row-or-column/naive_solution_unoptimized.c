/*
 * @lc app=leetcode id=947 lang=c
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    // how many stones can be removed
    int removableStones = 0;
    int stoneRemoved[stonesSize];
    int alignedCount[stonesSize];
    bool notDone;
    // initialization
    for (int i = 0; i < stonesSize; i++) {
        alignedCount[i] = 0;
        stoneRemoved[i] = 0;
    }
    // printf("%d: ", stonesSize);
    while (notDone) {
        notDone = false;
        // step1: track how many stones are on the same row/col for each stone
        // removable when the count is larger than 0
        for (int i = 0; i < stonesSize; i++) {
            alignedCount[i] = 0;
            if (stoneRemoved[i] == 1) {continue;}
            for (int j = 0; j < stonesSize; j++) {
                if (stoneRemoved[j] == 1) {continue;}
                if (i != j && (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])) {
                    // same coordinate condition does not exist
                    alignedCount[i]++;
                }
            }
        }
        // step2: remove (first) stone with count > 0
        for (int i = 0; i < stonesSize; i++) {
        }
        for (int i = 0; i < stonesSize; i++) {
            if (alignedCount[i] > 0) {
                stoneRemoved[i] = 1; //remove
                removableStones++;
                notDone = true;
                break;
            }
        }
    }
    return removableStones;
}
// @lc code=end

