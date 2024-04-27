//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    Node *getMid(Node *head) {
        Node *slow = head, *fast = head->next;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node *merging(Node *l, Node *r) {
        if(!l)
            return r;
            
        if(!r)
            return l;
            
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        while(l and r) {
            if(l->data <= r->data) {
                temp->next = l;
                l->prev = temp;
                l = l->next;
            } else {
                temp->next = r;
                r->prev = temp;
                r = r->next;
            }
            
            temp = temp->next;
        }
        
        while(l) {
            temp->next = l;
            l->prev = temp;
            l = l->next;
            temp = temp->next;
        }
        
        while(r) {
            temp->next = r;
            r->prev = temp;
            r = r->next;
            temp = temp->next;
        }
        
        dummy->next->prev = NULL;
        return dummy->next;
    }

    Node *sortDoubly(struct Node *head) {
        if(!head or !head->next)
            return head;
        
        Node *left = head;
        Node *mid = getMid(head);
        Node *right = mid->next;
        mid->next = NULL;
        
        Node *res = merging(sortDoubly(left), sortDoubly(right));
        return res;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends