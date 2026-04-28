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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int res = 0;
        int remain_n = 0;
        ListNode* cur = nullptr;
        ListNode* list_res = new ListNode(0);
        ListNode* a = list_res;
        while (l1 && l2) {
            res = l1->val + l2->val + remain_n;
            remain_n = res / 10;
            a->next = new ListNode();
            if (remain_n == 0) {
                a->next->val = res;
            } else {
                a->next->val = res % 10;
            }
            a = a->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            cur = l1;
        } else if (l2) {
            cur = l2;
        }
        while (cur) {
            res = cur->val + remain_n;
            remain_n = res / 10;
            a->next = new ListNode();
            if (remain_n == 0) {
                a->next->val = res;
            } else {
                a->next->val = res % 10;
            }
            a = a->next;
            cur = cur->next;
        }
        if (remain_n) {
            a->next = new ListNode();
            a->next->val = remain_n;
        }
        return list_res->next;
    }
};
