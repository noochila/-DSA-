//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        
        if(head==nullptr || head->next==nullptr)
        return head;
        
        
        Node* zero,*one,*two;
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
        Node* twohead=new Node(-1);
        zero=zerohead;
        one=onehead;
        two=twohead;
        
        
        Node* curr=head;
        
        while(curr!=nullptr)
        {
            if(curr->data==0)
            {
                zero->next=curr;
                zero=curr;
            }else if(curr->data==1)
            {
                one->next=curr;
                one=curr;
            }else {
                two->next=curr;
                two=curr;
            }
            curr=curr->next;
        }
        
        two->next=nullptr;
        
        if(onehead->next)
        zero->next=onehead->next;
        else if(twohead->next)
        zero->next=twohead->next;
        else
        zero->next=nullptr;
        
        if(twohead->next)
        one->next=twohead->next;
        else
        one->next=nullptr;
        
        if(zerohead->next)
        return zerohead->next;
        else
        return onehead->next;
        
        
        
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends