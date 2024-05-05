//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        
        
        
        // add code here.
        if(root==NULL)
        return {};
        
        map<int,map<int,vector<int>>> mp;
        
        queue<pair<Node *,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        vector<int> ans;
        

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
           
            
            Node* n=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            
           mp[x][y].push_back(n->data);
            if(n->left!=NULL)
            {
                q.push({n->left,{x-1,y+1}});
                
            }
            
            if(n->right!=NULL)
            {
                q.push({n->right,{x+1,y+1}});
            }
            
        }
        
        
        
        for(auto i:mp)
        {
            int sum=0;
            for(auto j:i.second )
            {
                for(auto k:j.second)
                sum+=k;
            }
            ans.push_back(sum);
            
            
        }
        
        return ans;
        
        
        
    
    }
};

//{ Driver Code Starts.
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}
// } Driver Code Ends