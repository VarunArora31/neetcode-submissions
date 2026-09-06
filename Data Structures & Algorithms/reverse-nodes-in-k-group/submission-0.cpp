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
    pair<ListNode*, ListNode*> rev(ListNode* head, int k) {
        ListNode* curr = head, *prev = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {curr, prev};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }
        len /= k;
        if (len == 0) return head;
        temp = head;
        ListNode* prevTail = nullptr;
        ListNode* newHead = nullptr;
        for (int i = 0; i < len; i++) {
            ListNode* groupTail = temp;
            auto [nextNode, groupHead] = rev(temp, k);
            if (newHead == nullptr) newHead = groupHead;
            if (prevTail != nullptr) prevTail->next = groupHead;
            groupTail->next = nextNode;
            prevTail = groupTail;
            temp = nextNode;
        }  
        return newHead;
    }
};
