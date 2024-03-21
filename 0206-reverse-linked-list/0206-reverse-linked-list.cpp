class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;

        while (curr != nullptr) {
           temp=prev;
           prev=curr;
           curr=curr->next;
           prev->next=temp;
          

        }

        return prev; // Return the new head of the reversed list
    }
};
