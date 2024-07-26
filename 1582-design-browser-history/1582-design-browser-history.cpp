class Node {
public:
    string data;
    Node *prev, *next;

    Node(string data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class BrowserHistory {
public:
    Node* curr;

    BrowserHistory(string homepage) { curr = new Node(homepage); }

    void visit(string url) {

        Node* temp = new Node(url);
        temp->prev = curr;
        curr->next = temp;
        curr = temp;
    }

    string back(int steps) {

      while (curr->prev && steps-- > 0) {
      // Move back one node by setting the current node to the previous node
      curr = curr->prev;
    }
    // Return the URL represented by the current node
    return curr->data;
    }

    string forward(int steps) {

        // While there are next nodes and we haven't gone forward enough steps yet
    while (curr->next && steps-- > 0) {
      // Move forward one node by setting the current node to the next node
      curr = curr->next;
    }
    // Return the URL represented by the current node
    return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */