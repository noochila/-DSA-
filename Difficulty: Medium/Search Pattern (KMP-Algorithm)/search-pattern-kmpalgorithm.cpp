//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
   vector<int>LPS;
   void buildLPS(string &pattern)
   {
       int n=pattern.size();
       LPS.resize(n,0);
       
       int i=1;
       int len=0;
       
       while(i<n)
       {
           if(pattern[len]==pattern[i])
           {
               len++;
               LPS[i]=len;
               i++;
           }else
           {
               if(len-1>=0)
               len=LPS[len-1];
               else
               {
               LPS[i]=0;
               i++;
                   
               }
               
           }
       }
       
       
   }
    
    
    vector<int> KMP(string &text,string &pattern)
    {
        buildLPS(pattern);
        vector<int>temp;
        
        int i=0;
        int j=0;
        int n=text.size();
        int m=pattern.size();
        while(i<n)
        {
            if(text[i]==pattern[j])
            {
                i++,j++;
            }
            
            if(j==m)
            {
                temp.push_back(i-j);
                j=LPS[j-1];
                
            }else if(i<n && text[i]!=pattern[j])
            {
                if(j!=0)
                j=LPS[j-1];
                else
                i++;
            }
        }
        return temp;
    }
    
  
    
    vector<int> search(string& pat, string& txt) {
        // code here
        
        return KMP(txt,pat);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends