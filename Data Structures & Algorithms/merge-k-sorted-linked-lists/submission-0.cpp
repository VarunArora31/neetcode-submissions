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

struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i]) minHeap.push(lists[i]);
        }
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            curr->next = top;
            curr = curr->next;
            if (top->next) {
                minHeap.push(top->next);
                top->next = nullptr;
            }
        }
        head = head->next;
        return head;
    }
};
