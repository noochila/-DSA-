/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* first = headA;
        ListNode* second = headB;

        if (first == nullptr || second == nullptr)
            return nullptr;

    
        while ( first!=nullptr && second!=nullptr && first != second) {

            first = first->next;
            second = second->next;
            if (first == second)
                return first;

            if (first == nullptr)
                first = headB;
            if (second == nullptr)
                second = headA;
        }
        return first;
    }
};