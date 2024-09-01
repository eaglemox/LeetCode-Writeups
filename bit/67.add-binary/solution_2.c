/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start
#define MAXLEN 50000
#define max(a, b) ((a) > (b) ? (a) : (b))

char* addBinary(char* a, char* b){
    size_t alen = strnlen(a, MAXLEN);
    size_t blen = strnlen(b, MAXLEN);
    const size_t clen = max(alen, blen) + 1;
    size_t j = 0;
    int8_t aa, bb;
    char cc; 
    int8_t carry = 0;
    char *c = malloc(clen + 1);
    memset(c, '\0', clen + 1);
    do {
        aa = (alen > 0) ? a[--alen] - '0' : 0;
        bb = (blen > 0) ? b[--blen] - '0' : 0;
        cc = (aa ^ bb ^ carry) + '0';
        carry = (aa & bb) | (aa & carry) | (bb & carry);
        c[clen - 1 - j++] = cc;
    } while (alen > 0 || blen > 0 || carry > 0);

    if (c[0] == '\0') {
        // use bitwise
        memmove(c, c + 1, clen);
    }
    
    return c;
}
// @lc code=end

