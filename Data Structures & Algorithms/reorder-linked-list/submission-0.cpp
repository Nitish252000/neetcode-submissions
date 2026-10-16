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
    void reorderList(ListNode* head) {
       if(head==NULL || head->next==NULL)return;
        vector<ListNode*>vec;
        ListNode* curr=head;
        while(curr!=NULL){
            vec.push_back(curr);
            curr=curr->next;
        }
        int start=0, end=vec.size()-1;
        while(start<end){
            vec[start]->next=vec[end]; // Link start node to end node
            start++;
            vec[end]->next=vec[start]; // Link end node to the new start node
            if(start==end)break;
            end--;
        }
        vec[start]->next=nullptr; 
    }
};
