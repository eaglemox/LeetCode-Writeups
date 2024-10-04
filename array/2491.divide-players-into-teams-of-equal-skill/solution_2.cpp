/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    long long dividePlayers(vector<int>& skill) {
        // Hash table Time: O(N + N) = O(N), Space: O(skill.range)
        long long target = 0, len = skill.size();
        // if (len == 2) {
        //     return skill[0] * skill[1];
        // }
        unordered_map<int, int> hashTable;
        for (int num : skill) {
            target += num;
            hashTable[num]++;
        }
        // total cannot divided into equal teams
        // if (target % (len / 2)) {
        //     return -1;
        // }
        target /= len / 2;

        long long chemistry = 0;
        // for (auto& pair : hashTable) {
        //     cout << pair.first << pair.second << endl;
        for (auto& [skill_a, count] : hashTable) {
            int skill_b = target - skill_a;
            if (hashTable.find(skill_b) == hashTable.end() ||
                count != hashTable[skill_b]) {
                return -1;
            }
            chemistry += (long long)skill_a * skill_b * count;
        }

        return chemistry / 2;
    }
};
// @lc code=end
