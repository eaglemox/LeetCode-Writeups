/*
 * @lc app=leetcode id=2458 lang=cpp
 *
 * [2458] Height of Binary Tree After Subtree Removal Queries
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        unordered_map<int,int> heightMap; // {node, max height after remove}
        int maxHeight = 0;
        dfsLR(root, 0, maxHeight, heightMap);
        maxHeight = 0;
        dfsRL(root, 0, maxHeight, heightMap);
        for (int query : queries) {
            result.push_back(heightMap[query]);
        }
        return result;
    }

private:
    void dfsLR(TreeNode* root, int height, int& maxHeight, unordered_map<int,int>& heightMap) {
        if (!root) {return;} // base case
        heightMap[root->val] = maxHeight;
        maxHeight = max(maxHeight, height);

        dfsLR(root->left, height + 1, maxHeight, heightMap);
        dfsLR(root->right, height + 1, maxHeight, heightMap);
    }

    void dfsRL(TreeNode* root, int height, int& maxHeight, unordered_map<int,int>& heightMap) {
        if (!root) {return;} // base case
        heightMap[root->val] = max(heightMap[root->val], maxHeight);
        maxHeight = max(maxHeight, height);

        dfsRL(root->right, height + 1, maxHeight, heightMap);
        dfsRL(root->left, height + 1, maxHeight, heightMap);
    }
};
// @lc code=end

