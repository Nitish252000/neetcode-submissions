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
    ListNode* merge(ListNode* temp1, ListNode* temp2) {
        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                tail->next = temp1;
                tail = tail->next;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                tail = tail->next;
                temp2 = temp2->next;
            }
        }
        if (temp1 != NULL) {
            tail->next = temp1;
        }
        if (temp2 != NULL) {
            tail->next = temp2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // vector<int> nums;
        // for (auto list : lists) {
        //     while (list != NULL) {
        //         nums.push_back(list->val);
        //         list = list->next;
        //     }
        // }

        // ListNode* dummy = new ListNode(0);
        // ListNode* temp = dummy;
        // sort(nums.begin(), nums.end());

        // for (auto& num : nums) {
        //     ListNode* node = new ListNode(num);
        //     temp->next = node;
        //     temp = temp->next;
        // }
        // return dummy->next;
        if (lists.empty()) return nullptr;

        int n = lists.size();

        while (n > 1) {
            int k = 0;

            for (int i = 0; i < n; i += 2) {
                if (i + 1 < n)
                    lists[k++] = merge(lists[i], lists[i + 1]);
                else
                    lists[k++] = lists[i];
            }

            n = k;
        }

        return lists[0];
    }
};
