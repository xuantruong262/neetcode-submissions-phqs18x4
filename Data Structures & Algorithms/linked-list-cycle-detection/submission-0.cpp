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
    bool hasCycle(ListNode* head) {
        set<ListNode*> checker;
        ListNode *m = head;
        bool res = false;
        while(m) {
            auto a = checker.insert(m);
            if(!a.second){
                res = true;
                break;
            }
            m = m->next;
        }
        return res;
    }
};
