/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start
int mySqrt(int x) {
    if (x == 0) {return 0;}
    // binary search
    // upper bound of sqrt() is 46340, which the largest int if x <= 2^31-1
    int l = 0, r = 46340; // prevent int overflow
    while (l <= r) {
        int mid = l + (r - l) / 2;
        printf("[%d, %d]: %d\n", l, r, mid);
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            l = mid + 1;
        } else if (mid * mid > x) {
            r = mid - 1;
        }
    } 
    return r; // r is the floor sqrt (l = mid+1, r = mid-1)
}
// @lc code=end

