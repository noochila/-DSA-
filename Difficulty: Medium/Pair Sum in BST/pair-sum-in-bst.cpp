//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class BSTIterator
{
public:
    stack<Node *> s;
    bool reverse; // reverse is true means it's before else it's next

    BSTIterator(Node *root, bool reverse)
    {
        this->reverse = reverse;
        pushALL(root);
    }

    int next()
    {
        Node *temp = s.top();
        if (!reverse)
        {

            s.pop();
            pushALL(temp->right);
        }
        else
        {

            s.pop();
            pushALL(temp->left);
        }

        return temp->data;
    }

    bool hasNext()
    {

        return !s.empty();
    }

    void pushALL(Node *root)
    {
        if (!reverse)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
        }
        else
        {
            while (root)
            {
                s.push(root);
                root = root->right;
            }
        }
    }
};


class Solution {
  public:
    bool findTarget(Node *root, int k) {
        // your code here.
        
        if(root==nullptr)
        return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i=l.next(),j=r.next();

    while(i<j)
    {
        int sum=i+j;
        if(sum==k)
        return true;
        else if(sum<k)
        {
            i=l.next();
        }else
        j=r.next();
    }

    return false;


  

        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution obj;
        cout << obj.findTarget(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends