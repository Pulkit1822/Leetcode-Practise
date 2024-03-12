/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        prefixSumToNode[0] = dummy;

        while (current != nullptr) {
            prefixSum += current->val;
            prefixSumToNode[prefixSum] = current;
            current = current->next;
        }

        prefixSum = 0;
        current = dummy;

        while (current != nullptr) {
            prefixSum += current->val;
            current->next = prefixSumToNode[prefixSum]->next;
            current = current->next;
        }
        return dummy->next;
    }
};
// @lc code=end

