/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head;
        while (curr && curr->next) {
            int gcd = std::gcd(curr->val, curr->next->val);
            ListNode* newNode = new ListNode(gcd);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        return head;
    }
};
// @lc code=end

