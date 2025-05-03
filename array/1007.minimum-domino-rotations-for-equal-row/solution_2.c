/*
 * @lc app=leetcode id=1007 lang=c
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    // We check if a row can be adjust to equal value, tops[0] or bottoms[0]
    // Return the min number of rotations required of either row
    int length = topsSize;
    // Candidate value: tops[0], bottoms[0]
    int val1Dominoes = 0, val2Dominoes = 0,
        val1TopCount = 0, val1BottomCount = 0,
        val2TopCount = 0, val2BottomCount = 0;
    for (int i = 0; i < length; i++) {
        val1TopCount += (tops[i] == tops[0]);
        val2TopCount += (tops[i] == bottoms[0]);
        val1BottomCount += (bottoms[i] == tops[0]);
        val2BottomCount += (bottoms[i] == bottoms[0]);
        val1Dominoes += (tops[i] == tops[0] || bottoms[i] == tops[0]);
        val2Dominoes += (tops[i] == bottoms[0] || bottoms[i] == bottoms[0]);
    }
    
    int val1MinRotations = length - ((val1TopCount > val1BottomCount) ? val1TopCount : val1BottomCount),
        val2MinRotations = length - ((val2TopCount > val2BottomCount) ? val2TopCount : val2BottomCount);
    if (val1Dominoes < length && val2Dominoes < length) {
        return -1;
    } else if (val1Dominoes == length && val2Dominoes < length) {
        return val1MinRotations;
    } else if (val1Dominoes < length && val2Dominoes == length) {
        return val2MinRotations;
    }
    return (val1MinRotations < val2MinRotations) ? val1MinRotations : val2MinRotations;
}
// @lc code=end

