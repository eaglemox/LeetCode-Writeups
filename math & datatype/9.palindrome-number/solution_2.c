/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
bool isPalindrome(int x) {
    if (x < 0) { // negative number contain '-', can never be a palindrome
        return false;
    }
    long reverse = 0; // prevent int overflow (reverse * 10)
    int temp = x;
    int digit;
    while (temp != 0) { // reverse x throgh math operations
        digit = temp % 10;
        reverse = reverse * 10 + digit;// adding new digit from back
        /* if not reversed
        reverse = reverse + digit * 10^carry;
        */  
        temp = temp / 10;
    }
    return (reverse == x);
}
// @lc code=end

