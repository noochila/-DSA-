//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
 
  public:
    // Constructor for initializing the cache capacity with the given value.
     std::list<int> dll; 
    
    // Hash map to store key -> (iterator to DLL, value)
    std::map<int, std::pair<std::list<int>::iterator, int>> mp; 
    
    // Cache capacity
    int cap; 

public:
    // Constructor to initialize the cache with given capacity
    LRUCache(int cap) {
        this->cap = cap;
    }

    // Utility function to move an accessed key to the front of the list
    void pushToFront(int key) {
        // Remove the key from its current position
        dll.erase(mp[key].first); 
        // Add it to the front of the list
        dll.push_front(key); 
        // Update the iterator in the map
        mp[key].first = dll.begin(); 
    }

    // Function to return value corresponding to the key
    int get(int key) {
        // If the key does not exist, return -1
        if (mp.find(key) == mp.end()) return -1;
        
        // Move the key to the front as it is accessed
        pushToFront(key);
        
        // Return the value associated with the key
        return mp[key].second; 
    }

    // Function to insert or update key-value pairs
    void put(int key, int value) {
        // If the key already exists
        if (mp.find(key) != mp.end()) {
            // Update the value
            mp[key].second = value; 
            // Move the key to the front
            pushToFront(key); 
        } else {
            // If the key does not exist, insert it
            dll.push_front(key); 
            // Add the key-value pair to the map
            mp[key] = {dll.begin(), value}; 
            // Decrease capacity as a new item is added
            --cap; 
        }

        // If capacity is exceeded, evict the least recently used item
        if (cap < 0) {
            // Identify the least recently used key (back of DLL)
            int delKey = dll.back(); 
            // Remove it from the DLL
            dll.pop_back(); 
            // Remove it from the map
            mp.erase(delKey); 
            // Restore capacity
            ++cap; 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends