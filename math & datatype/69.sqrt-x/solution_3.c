/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start
int mySqrt(int x) {
    if (x == 0 || x == 1) {return x;}
    // https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Heron's_method
    double sqrt = 46340 / 2, temp = 0;
    int count = 0;
    while (sqrt != temp) {
        temp = sqrt;
        sqrt = (sqrt + x / sqrt) / 2;
        count++;
    }
    printf("converge at %d interations.\n", count);
    return sqrt;
}
// @lc code=end

