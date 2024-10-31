//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        if(head==nullptr)
        {
            Node* temp=getNode(x);
            return temp;
        }
        
        if(x<=head->data)
        {
            Node* temp=getNode(x);
            temp->next=head;
            head->prev=temp;
            return temp;
        }
        
        Node* curr=head;
        Node* prev=nullptr;
        
        while(curr!=nullptr)
        {
            prev=curr;
            curr=curr->next;
            
            if(curr && curr->data>x)
            {
                break;
            }
        }
        
        Node* temp=getNode(x);
        prev->next=temp;
        temp->prev=prev;
        
        if(curr!=nullptr)
        {
            temp->next=curr;
            curr->prev=temp;
        }else
        {
            temp->next=nullptr;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends