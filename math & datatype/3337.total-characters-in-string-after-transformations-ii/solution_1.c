/*
 * @lc app=leetcode id=3337 lang=c
 *
 * [3337] Total Characters in String After Transformations II
 */

// @lc code=start
#define MOD 1000000007

void matMul(long long** a, long long** b) {
    long long **ret = calloc(26, sizeof(long long*));
    for (int i = 0; i < 26; i++) {
        ret[i] = calloc(26, sizeof(long long));
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        memcpy(a[i], ret[i], 26 * sizeof(long long));
    }
}

long long** binaryPower(long long** orig, int pow) {
    long long** ret = calloc(26, sizeof(long long*));
    long long** base = calloc(26, sizeof(long long*));
    for (int i = 0; i < 26; i++) {
        ret[i] = calloc(26, sizeof(long long));
        ret[i][i] = 1;
        base[i] = calloc(26, sizeof(long long));
        memcpy(base[i], orig[i], 26 * sizeof(long long));
    }
    while (pow) {
        if (pow & 1) {
            matMul(ret, base);
        }
        matMul(base, base);
        pow >>= 1; // divided by 2
    }
    return ret;
}

void showMatrix(long long** mat) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int lengthAfterTransformations(char* s, int t, int* nums, int numsSize) {
    // Compared to the previous problem, the transformation rule is defined by
    // the array 'nums' instead of a fixed rule. The problem can be modeled as a
    // linear transformation: Vt = T^t * V0, where V is the character count
    // vector, and T is the transformation matrix.
    int length = 0, count[26] = {0};

    // Initialize transform matrix
    long long** T = malloc(26 * sizeof(int*));
    for (int i = 0; i < 26; i++) {
        T[i] = malloc(26 * sizeof(long long));
        for (int j = 0; j < 26; j++) {
            T[i][j] = 0;
        }
    }
    // Column represent how original count contribute to each letters after
    // transformation
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= nums[i]; j++) {
            T[(i + j) % 26][i] = 1;
        }
    }
    // showMatrix(T, 26, 26);

    // Compute T^t using binary exponentiation
    long long **Tt = binaryPower(T, t);

    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int tmp = 0;
        for (int j = 0; j < 26; j++) {
            tmp = (tmp + Tt[i][j] * count[j]) % MOD;
        }
        length = (length + tmp) % MOD;
    }

    return length;
}
// @lc code=end

