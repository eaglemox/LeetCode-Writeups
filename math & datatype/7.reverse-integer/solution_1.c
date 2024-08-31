/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
int reverse(int x){
    // digits of integer x is reversed one by one backward, negative sign is automatically considered
    // b.c. the digit is calculated through '%' (e.g. temp = -321, digit = -321 % 10 = -1)   
    int reverse = 0; // when overflow can happen, return 0
    int temp = x;
    int digit;
    while (temp != 0) {
        digit = temp % 10; // last digit of temp
    if (reverse > (INT_MAX / 10) || reverse < (INT_MIN / 10)) {
        return 0;
    }
        reverse = reverse * 10 + digit;
        temp = temp / 10;
    }
    return reverse;
}
// @lc code=end

