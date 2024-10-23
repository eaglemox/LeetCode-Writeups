/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Two pass DFS approach, Time: O(2N), Space: O(N)
        computeLevelSum(root, 0);
        updateCousinSum(root, 0, 0);
        return root;
    }
private:
    int levelSums[100000];

    void computeLevelSum(TreeNode* node, int level) {
        if (!node) {return;} // base case
        levelSums[level] += node->val;
        computeLevelSum(node->left, level + 1);
        computeLevelSum(node->right, level + 1);
    }

    void updateCousinSum(TreeNode* node, int level, int siblingSum) {
        if (!node) {return;} // base case
        // first two level cannot have cousin
        if (level < 2) {node->val = 0;}
        else {
            node->val = levelSums[level] - siblingSum;
        }
        // Compute siblingSum for children node
        int childSum = 0;
        if (node->left) {childSum += node->left->val;}
        if (node->right) {childSum += node->right->val;}

        updateCousinSum(node->left, level + 1, childSum);
        updateCousinSum(node->right, level + 1, childSum);
    }
};
// @lc code=end

