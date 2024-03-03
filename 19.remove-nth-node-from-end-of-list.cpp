/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
class Solution {
public:

    int getlength(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr) {
            return nullptr;
        }

        int length = getlength(head);
        ListNode* node = NULL;
        if (length <= 1) return node;

        ListNode* curr = head;
        ListNode* prev = NULL;

        int position = length - n;
        int count = 1;

        if (length == n) {
            head = head->next;
            curr->next = NULL;
            delete curr;
            return head;
        }

        while (count <= position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == NULL) {
            prev->next = NULL;
        }
        else {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

        return head;

    }
};
// @lc code=end

