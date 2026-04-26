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
        vector<ListNode*> box;
        ListNode* cur = head;
        while (cur) {
            box.push_back(cur);
            cur = cur->next;
        }
        cur = head;
        int len = box.size();
        int count = 1;
        while (count <= len/2) {
            head->next = box[len - count];
            head = head->next;
            head->next = box[count];
            head = head->next;
            count += 1;
        }
        head->next = nullptr;
        head = cur;
    }
};
