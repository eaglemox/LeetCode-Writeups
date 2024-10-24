/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Time: O(N), Space: O(N)
        if (!root1 && !root2) {return true;} // both reach end
        if (!root1 || !root2) {return false;} // one is null
        if (root1->val != root2->val) {return false;} // value unequal
        
        // all child node combination
        bool swap, noSwap;
        swap = flipEquiv(root1->left, root2->right) \
             & flipEquiv(root1->right, root2->left);
        noSwap = flipEquiv(root1->left, root2->left) \
               & flipEquiv(root1->right, root2->right);
        // swapped / no swapped branches of current node is equivalent
        return swap | noSwap;
    }
};
// @lc code=end

