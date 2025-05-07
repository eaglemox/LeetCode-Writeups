/*
 * @lc app=leetcode id=2058 lang=c
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    // Local maxima: curr > prev, next | Local minima: curr < prev, next
    // Track the first and latest index of critical point
    // Time: O(#nodes), Space: O(1)
    *returnSize = 2;
    int* result = malloc(*returnSize * sizeof(int));
    result[0] = result[1] = -1;
    int first = -1, latest = -1, index = 1;
    struct ListNode* curr = head;
    while (curr && curr->next && curr->next->next) {
        if (curr->next->val > curr->val && curr->next->val > curr->next->next->val ||
            curr->next->val < curr->val && curr->next->val < curr->next->next->val) {
            if (first == -1) {first = index;}
            else {result[1] = index - first;}
            if (latest != -1 && (result[0] == -1 || (index - latest) < result[0])) {
                result[0] = index - latest;
            }
            latest = index;
        }
        curr = curr->next;
        index++;
    }
    return result;
}
// @lc code=end

