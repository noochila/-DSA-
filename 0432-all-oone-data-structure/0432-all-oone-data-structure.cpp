#include <unordered_map>
#include <set>
#include <string>

struct Node {
    int count;
    Node *prev, *next;
    std::set<std::string> s;
    Node(int c) : count(c), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    Node* head;
    Node* tail;
    std::unordered_map<std::string, Node*> mp;

    AllOne() {
        head = new Node(0); // Dummy head node
        tail = new Node(0); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    void inc(std::string key) {
        if (mp.find(key) == mp.end()) {
            // Key doesn't exist, insert it with count 1
            if (head->next == tail || head->next->count != 1) {
                Node* newNode = new Node(1);
                newNode->next = head->next;
                newNode->prev = head;
                head->next->prev = newNode;
                head->next = newNode;
            }
            head->next->s.insert(key);
            mp[key] = head->next;
        } else {
            // Key exists, move it to the next node with count + 1
            Node* curr = mp[key];
            Node* nextNode = curr->next;
            if (nextNode == tail || nextNode->count != curr->count + 1) {
                Node* newNode = new Node(curr->count + 1);
                newNode->next = nextNode;
                newNode->prev = curr;
                curr->next = newNode;
                nextNode->prev = newNode;
            }
            curr->next->s.insert(key);
            mp[key] = curr->next;
            curr->s.erase(key);
            if (curr->s.empty()) {
                removeNode(curr);
            }
        }
    }

    void dec(std::string key) {
        Node* curr = mp[key];
        if (curr->count == 1) {
            // If count becomes 0, remove the key completely
            curr->s.erase(key);
            mp.erase(key);
            if (curr->s.empty()) {
                removeNode(curr);
            }
        } else {
            Node* prevNode = curr->prev;
            if (prevNode == head || prevNode->count != curr->count - 1) {
                Node* newNode = new Node(curr->count - 1);
                newNode->next = curr;
                newNode->prev = prevNode;
                prevNode->next = newNode;
                curr->prev = newNode;
            }
            curr->prev->s.insert(key);
            mp[key] = curr->prev;
            curr->s.erase(key);
            if (curr->s.empty()) {
                removeNode(curr);
            }
        }
    }

    std::string getMaxKey() {
        return tail->prev == head ? "" : *tail->prev->s.begin();
    }

    std::string getMinKey() {
        return head->next == tail ? "" : *head->next->s.begin();
    }

private:
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};
