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
    ListNode* findMid(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* mid = findMid(head);
        ListNode* first = head;
        ListNode* second = mid->next;
        mid->next = NULL;  // break in half

        // reverse second half
        ListNode* curr = second;
        ListNode* prev = NULL;
        ListNode* temp;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        second = prev;  // Point to reverse list

        while (second != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};
