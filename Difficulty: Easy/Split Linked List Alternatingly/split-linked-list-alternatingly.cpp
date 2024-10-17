//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        
        Node* head1=new Node(-1);
        Node* head2=new Node(-1);
        
        
        Node*curr1=head1;
        Node*curr2=head2;
        
        Node* curr=head;
        bool chance=true;
        
        while(curr!=nullptr)
        {
            
            if(chance)
            {
                curr1->next=curr;
                curr1=curr1->next;
                
            }else
            {
                curr2->next=curr;
                curr2=curr2->next;
            }
            
        
            
            curr=curr->next;
            chance=!chance;
        }
        
        curr1->next=nullptr;
        curr2->next=nullptr;
        
        return {head1->next,head2->next};
    }
    
    
    
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends