/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *output = new ListNode();
        ListNode *temp = output;
        int carry = 0; // initailize new variable faster than re-assignment?
        while (l1 || l2 || carry != 0)
        {
            int num_1 = (l1) ? l1->val : 0; // check l1 null, faster than l1 != NULL????
            int num_2 = (l2) ? l2->val : 0;
            int sum = (num_1 + num_2 + carry) % 10;
            carry = (num_1 + num_2 + carry) / 10;
            // cout << sum << ", " << carry << endl;
            temp->next = new ListNode(sum);
            temp = temp->next;

            l1 = (l1) ? l1->next : NULL;
            l2 = (l2) ? l2->next : NULL;
        }
        return output->next;
    }
};
// @lc code=end
