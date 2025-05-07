/*
 * @lc app=leetcode id=817 lang=c
 *
 * [817] Linked List Components
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    // The problem is trying to ask is finding the number of consecutive parts (segments) in 
    // the linked list that with elements also be in nums. (order in nums doesn't matter)
    // Ex.2 head = [0,1,2,3,4], nums = [0,3,1,4] -> no 2 in nums
    // Thus only [0, 1] and [3, 4] are "connected components"
    int result = 0;
    int bin[10000] = {0}; // 1 <= n <= 10e4

    for (int i = 0; i < numsSize; i++) {
        bin[nums[i]] = 1;
    }
    int flag = 0;
    while (head) {
        if (!flag && bin[head->val]) {
            result++;
        }
        flag = bin[head->val];
        head = head->next;
    }
    return result;
}
// @lc code=end

