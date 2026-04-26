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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dum = new ListNode;
        ListNode *cur_dum = dum;
        while(list1 && list2){
            if(list1->val < list2->val){
                cur_dum->next = list1;
                list1 = list1->next;
            }
            else{
                cur_dum->next = list2;
                list2 = list2->next;
            }
            cur_dum = cur_dum->next;
        }

        if(list1){
            cur_dum->next = list1;
        }
        else {
            cur_dum->next = list2;
        }
        return dum->next;
    }
};
