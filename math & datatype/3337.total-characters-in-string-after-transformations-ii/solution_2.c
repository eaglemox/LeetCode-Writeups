/*
 * @lc app=leetcode id=3337 lang=c
 *
 * [3337] Total Characters in String After Transformations II
 */

// @lc code=start
long long Tt[26][26];
#define MOD 1000000007

void matMul(long long a[26][26], long long b[26][26]) {
    long long ret[26][26];
    memset(ret, 0, sizeof(ret));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(a, ret, sizeof(ret));
}

void binaryPower(long long base[26][26], int pow) {
    long long ret[26][26];
    memset(ret, 0, sizeof(ret));

    for (int i = 0; i < 26; i++) {
        ret[i][i] = 1;
    }
    while (pow) {
        if (pow & 1) {
            matMul(ret, base);
        }
        matMul(base, base);
        pow >>= 1; // divided by 2
    }
    memcpy(Tt, ret, sizeof(ret));
}

void showMatrix(long long mat[26][26]) {
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
    long long T[26][26];
    memset(T, 0, sizeof(T));

    // Column represent how original count contribute to each letters after
    // transformation
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= nums[i]; j++) {
            T[(i + j) % 26][i] = 1;
        }
    }
    // showMatrix(T, 26, 26);

    // Compute T^t using binary exponentiation
    binaryPower(T, t); // Tt is global variable

    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            length = (length + Tt[i][j] * count[j]) % MOD;
        }
    }

    return length;
}
// @lc code=end

