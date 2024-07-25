class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
         
         ListNode *fast=head;
         ListNode* slow=head;

         if(head==nullptr || head->next==nullptr)
         return true;

         while(fast->next!=nullptr && fast->next->next!=nullptr)
         {
            slow=slow->next;
            fast=fast->next->next;
         }
  


        ListNode* startNode=reverse(slow->next);

        ListNode* start=startNode;
        ListNode* end=head;

        while(start!=nullptr)
        {
            if(start->val!=end->val)
            {
                return false;
            }
            start=start->next;
            end=end->next;
        }
        return true;



    }
};