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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the priority queue
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }

        return ans->next;
    }
};