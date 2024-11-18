/*
 * @lc app=leetcode id=1486 lang=c
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
int xorOperation(int n, int start) {
    // i-th num is start add the i-th bit in binary
    // If 2nd bit of start is set, [1,3,5,7,9,11,13,15]
    // else, [3,5,7,9,11,13,15,17,19]
    if (start % 4 < 2) {
        switch (n % 4) {
            case 0:
                return 0;
            case 1:
                return start + 2 * (n - 1);
            case 2:
                return 2;
            case 3:
                return (start + 2 * (n - 1)) ^ 2;
        }
    } else { // start will cause carry
        switch (n % 4) {
            case 0:
                return start ^ 2 ^ (start + 2 * (n - 1));
            case 1:
                return start;
            case 2:
                return start ^ (start + 2 * (n - 1));
            case 3: // last ^ prev last = (prev last + 2) ^ prev last
                return start ^ 2;
        }
    }
    return 0; // never reach
}
// @lc code=end

