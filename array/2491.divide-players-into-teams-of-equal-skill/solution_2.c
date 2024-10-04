/*
 * @lc app=leetcode id=2491 lang=c
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
#include <stdio.h>
#define MAX_VAL 1000

long long dividePlayers(int* skill, int skillSize) {
    // Hash table Time: O(N), Space: O(skill.range)
    if (skillSize == 2) {return skill[0] * skill[1];}
    int freq[MAX_VAL+1]; // skill[i]: [1, 1000]
    for (int i = 0; i <= MAX_VAL; i++) {freq[i] = 0;}

    long long target = 0;
    for (int i = 0; i < skillSize; i++) {
        target += skill[i];
        freq[skill[i]]++;
    }

    if (target % (skillSize / 2)) {return -1;}
    target /= skillSize / 2;

    printf("target: %d\n", target);
    long long chemistry = 0;
    for (int i = 1; i <= MAX_VAL; i++) {
        if (freq[i] != 0) {
            int complement = target - i;
            printf("frequency %d: %d, %d: %d\n", i, freq[i], complement, freq[complement]);
            if (freq[i] != freq[complement] || freq[complement] == 0) {
                return -1;
            }
            chemistry += (long long)i * complement * freq[i];
        }
    }
    return chemistry / 2;
}
// @lc code=end

