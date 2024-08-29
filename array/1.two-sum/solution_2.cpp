#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        // fill hash table
        for(auto num = nums.begin(); num < nums.end(); num++){
            hashTable[*num] = int(distance(nums.begin(), num));
        }
        // for (auto it : hashTable){
        //     cout << it.first << ": " << it.second << endl;
        // }

        // find answer pair using hash table
        int complement, num_idx;
        for (auto num = nums.begin(); num < nums.end(); num++){
            complement = target - *num;
            num_idx = int(distance(nums.begin(), num));
            if (hashTable.count(complement) > 0 && hashTable[complement] != num_idx){
                return {num_idx, hashTable[complement]};
            }
        }
        return {};
    }
};