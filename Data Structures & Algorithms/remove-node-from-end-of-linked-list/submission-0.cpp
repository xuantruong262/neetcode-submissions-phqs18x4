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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> box;
        ListNode *cur = head;
        while(cur){
            box.push_back(cur);
            cur = cur->next;
        }
        int len = box.size();
        int rm_indx = len - n;
        if(rm_indx == 0){
            return head->next;
        }
        box[rm_indx - 1]->next = box[rm_indx]->next;
        return box[0];
    }
};
