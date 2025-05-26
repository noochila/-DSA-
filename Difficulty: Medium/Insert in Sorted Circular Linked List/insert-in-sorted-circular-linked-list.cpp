/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
      
       // code here
        // 1. Allocate the new node
        Node* newNode = new Node(data);

        /* ---------- Case 1: empty list ---------- */
        if (head == nullptr) {
            newNode->next = newNode;   // points to itself
            return newNode;
        }

        /* ---------- Case 2: insert before current head
             (i.e., new value is the new minimum) ---------- */
        if (data <= head->data) {
            // locate the last node (whose next is head)
            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            tail->next = newNode;  // last node → new node
            newNode->next = head;  // new node → old head
            return newNode;        // new node becomes the head
        }

        /* ---------- Case 3: insert somewhere after head ---------- */
        Node* curr = head;
        // move until we find the first node whose next value ≥ data
        while (curr->next != head && curr->next->data < data)
            curr = curr->next;

        // insert after curr
        newNode->next = curr->next;
        curr->next = newNode;

        return head; 
        
        
    }
};