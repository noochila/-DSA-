//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


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

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends