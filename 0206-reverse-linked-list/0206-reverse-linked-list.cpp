class Solution {
public:

    ListNode* solve(ListNode* head)
    {
        if( head==nullptr || head->next==nullptr )
        {
            return head;
        }
   


      ListNode* newHead=solve(head->next);
      ListNode* front=head->next;
      front->next=head;
      head->next=nullptr;

      return newHead;

        
   
      
    }


    ListNode* reverseList(ListNode* head) {
         
        //  ListNode*prev=nullptr;
        //  ListNode*curr=head;
        //  ListNode* next=nullptr;

        //  while(curr!=nullptr)
        //  {
        //     next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
            
        //  }
        //  return prev;

       return solve(head);
    }
};
