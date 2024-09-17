/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

// @lc code=start
#include <stdio.h>
#include <stdbool.h>
int getHash(int number) {
    int sum = 0;
    int r = number % 10;
    int q = number / 10;
    sum += r * r;
    while (q != 0) {
        r = q % 10;
        sum += r * r;
        q = q / 10;
    }
    return sum;
}
bool isHappy(int n) {
    if (n == 1) {return true;}
    int mask[1000] = {0};
    int temp = getHash(n);
    while (temp != 1 && mask[temp] == 0) {
        mask[temp] = 1; // mark seen hashed value
        // printf("%d\n", temp);
        temp = getHash(temp);
    }
    return (temp == 1) ? true : false;
}
// @lc code=end

