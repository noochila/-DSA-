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

        ListNode* dummy = new ListNode(-1);
    ListNode* ans = dummy;

    ListNode* h1 = list1;
    ListNode* h2 = list2;

    while (h1 != nullptr && h2 != nullptr) {
        if (h1->val == h2->val) {
            ans->next = h1;
            h1 = h1->next;
            ans = ans->next;

            ans->next = h2;
            h2 = h2->next;
            ans = ans->next;
        } else if (h1->val < h2->val) {
            ans->next = h1;
            h1 = h1->next;
            ans = ans->next;
        } else {
            ans->next = h2;
            h2 = h2->next;
            ans = ans->next;
        }
    }

    if (h1 != nullptr) {
        ans->next = h1;
    } else {
        ans->next = h2;
    }

    ListNode* mergedList = dummy->next;
    delete dummy; // Free the dummy node
    return mergedList;
        
    }
};