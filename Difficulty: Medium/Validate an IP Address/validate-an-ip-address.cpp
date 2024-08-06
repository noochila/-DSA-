//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        stringstream ss(str);
        string temp="";
        
        int count=0;
        
        
        while(getline(ss,temp,'.'))
        {
            count++;
            
            if(temp.size()>1 && temp[0]=='0')
            return false;
            
            
            if(count>4)
            return false;
            
            if(temp=="")
            return false;
            int val=stoi(temp);
            if(val>=0 && val<=255)
            continue;
            else
            return false;
        }
        
        if(count<4)
        return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends