/*
 * @lc app=leetcode id=1894 lang=c
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
int chalkReplacer(int* chalk, int chalkSize, int k) {
    unsigned int remainder;
    long long *sum = malloc(chalkSize * sizeof(long long));
    sum[0] = chalk[0];
    for (int i = 1; i < chalkSize; i++) {
        sum[i] =  sum[i-1] + chalk[i];
    }
    remainder = k % sum[chalkSize - 1];
    printf("%d = %lli * N + %d\n", k, sum[chalkSize - 1], remainder);
    int i = 0;
    while (sum[i] <= remainder) {i++;}
    return i;

    // binary search
    // int l = 0, r = chalkSize - 1;
    // while (l <= r) {
    //     int mid = l + (r - l) / 2;
    //     if (sum[mid] == remainder) {return mid + 1;}
    //     else if (sum[mid] < remainder) {
    //         l = mid + 1;
    //     } else {
    //         r = mid - 1;
    //     }
    // }
    // return l; // choose the lesser index
}
// @lc code=end

