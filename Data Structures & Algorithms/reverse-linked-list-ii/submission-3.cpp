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
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if no reversal is needed or list is empty
        if (left == right || head == nullptr) {
            return head;
        }

        // Dummy node handles the edge case where left = 1 perfectly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: Reach the node right before the 'left' position
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: In-place reversal of the sublist
        ListNode* curr = prev->next;  // The starting node of the sublist
        for (int i = 0; i < right - left; i++) {
            ListNode* forward = curr->next;  // Temporarily store the next node

            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }

        // Store the result pointer and clean up the dummy node memory
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};