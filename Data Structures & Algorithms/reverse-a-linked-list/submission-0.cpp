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
ListNode* newHead;
public:
    ListNode* rev(ListNode* head) {
        if (!head || !(head->next)) {
            return newHead = head;
        }
        ListNode* nextNode = rev(head->next);
        nextNode->next = head;
        head->next = nullptr;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        // [0,1,2,3]
        // 0 [1,2,3]
        // 0 1 [2, 3]
        // 0 1 2 [3]
        newHead = nullptr;
        rev(head);
        return newHead;
    }
};
