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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        for (auto list : lists) {
            while (list != NULL) {
                nums.push_back(list->val);
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        sort(nums.begin(), nums.end());

        for (auto& num : nums) {
            ListNode* node = new ListNode(num);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};
