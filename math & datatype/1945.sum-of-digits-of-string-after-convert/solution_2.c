/*
 * @lc app=leetcode id=1945 lang=c
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
int sumDigit(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int getLucky(char* s, int k) {
    int sum = 0;
    // convert to int, perform transform
    for (int i = 0; s[i] != '\0'; i++) {
        int digit = s[i] - 'a' + 1;
        printf("%d ", digit);
        sum += (digit / 10) + (digit % 10); 
    }
    printf("= %d\n", sum);

    while (k > 1) {
        sum = sumDigit(sum);
        k--;
    }
    return sum;
}
// @lc code=end

