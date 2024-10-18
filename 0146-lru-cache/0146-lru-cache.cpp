#include <map>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        else {
            Node* temp = mp[key];
            deleteNode(temp);
            insertNode(temp);
            return temp->value;
        }
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            deleteNode(temp);
            temp->value = value;
            insertNode(temp); 
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertNode(newNode);
            mp[key] = newNode;
        }
    }

private:
    void insertNode(Node* temp) {
        Node* curr = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = curr;
        curr->prev = temp;
    }

    void deleteNode(Node* temp) {
        Node* left = temp->prev;
        Node* right = temp->next;
        left->next = right;
        right->prev = left;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
