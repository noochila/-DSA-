//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        
        for(int i = 0; i < x.size(); i++) {
            if(!s.empty() && s.top() == '(' && x[i] == ')') {
                s.pop();
            } else if(!s.empty() && s.top() == '[' && x[i] == ']') {
                s.pop();
            } else if(!s.empty() && s.top() == '{' && x[i] == '}') {
                s.pop();
            } else {
                s.push(x[i]);
            }
        }
        
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends