//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
 int dis = 0;
unordered_map<Node*, Node*> mp;

void buildparent(Node* root, Node* par) {
    if (root == nullptr)
        return;

    mp[root] = par;

    buildparent(root->left, root);
    buildparent(root->right, root);
}

Node* findTar(Node* root, int target) {
    if (root == nullptr)
        return nullptr;

    if (root->data == target)
        return root;

    Node* leftResult = findTar(root->left, target);
    if (leftResult != nullptr)
        return leftResult;

    return findTar(root->right, target);
}

void solve(Node* root, int k, unordered_set<Node*>& vis) {
    if (root == nullptr || vis.find(root) != vis.end()) {
        dis = max(dis, k - 1); // Update dis correctly and use k-1 to get correct distance
        return;
    }

    vis.insert(root);

    solve(root->left, k + 1, vis);
    solve(root->right, k + 1, vis);
    solve(mp[root], k + 1, vis);
}

int minTime(Node* root, int target) {
    buildparent(root, nullptr);

    unordered_set<Node*> vis;

    Node* t = findTar(root, target);

    if (root == nullptr || t == nullptr)
        return 0;

    solve(t, 0, vis);

    return dis;
}
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends