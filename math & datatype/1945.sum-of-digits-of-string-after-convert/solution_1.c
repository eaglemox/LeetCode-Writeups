/*
 * @lc app=leetcode id=1945 lang=c
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
int sumDigit(int x) {
    int q = x / 10, r = x % 10;
    if (q < 10) {
        return q + r;
    } else {
        return sumDigit(q) + r;
    }
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

