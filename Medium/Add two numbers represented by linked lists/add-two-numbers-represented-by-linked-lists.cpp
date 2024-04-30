//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
Node* solve(Node* head1, Node* head2) {
    int carry = 0;
    Node* head = nullptr;
    Node* temp = nullptr;

    while (head1 != nullptr || head2 != nullptr || carry != 0) {
        int sum = (head1 ? head1->data : 0) + (head2 ? head2->data : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;
        Node* newNode = new Node(sum);
        if (head == nullptr) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }

    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int len(Node* num) {
    int length = 0;
    while (num != nullptr) {
        length++;
        num = num->next;
    }
    return length;
}

Node* append(Node* head) {
    Node* temp = new Node(0);
    temp->next = head;
    return temp;
}

Node* addTwoLists(Node* num1, Node* num2) {
   int n = len(num1);
int m = len(num2);

// Append zeros only if the first node of num1 or num2 is zero
if (n < m && num1->data == 0) {
    while (n < m) {
        num1 = append(num1);
        n++;
    }
} else if (n > m && num2->data == 0) {
    while (n > m) {
        num2 = append(num2);
        m++;
    }
}

num1 = reverse(num1);
num2 = reverse(num2);

Node* ans = solve(num1, num2);

// Reverse the result before returning
ans = reverse(ans);

// Remove leading zeros
while (ans->next != nullptr && ans->data == 0) {
    Node* temp = ans;
    ans = ans->next;
    delete temp;
}

return ans;

}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends