/*
 * @lc app=leetcode id=2040 lang=c
 *
 * [2040] Kth Smallest Product of Two Sorted Arrays
 */

// @lc code=start
int countMultiplicands(long long product, long long multiplier, int* nums2, int nums2Size) {
    int count = 0;
    int l = 0, r = nums2Size - 1;

    // Binary search the index that the number times multiplier just <= product
    while (l <= r) {
        int mid = (l + r) / 2;
        long long midProd = multiplier * nums2[mid];

        if ((multiplier >= 0 && midProd <= product) || (multiplier < 0 && midProd > product)) {
            // Mid must be higher
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }

    if (multiplier >= 0) {
        // Index < l will have lower product
        return l;
    } else {
        return nums2Size - l;
    }
}

long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2, int nums2Size, long long k) {
    // Binary search on result product value and its multiplicand (fix multiplier)
    long long l = -1E10, r = 1E10;
    long long result;
    while (l <= r) {
        long long count = 0, mid = (l + r) / 2;
        for (int i = 0; i < nums1Size; i++) {
            count += countMultiplicands(mid, (long long)nums1[i], nums2, nums2Size);
        }

        if (count < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
// @lc code=end

