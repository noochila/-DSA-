//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        
        vector<int> pos;
        vector<int>neg;
        
        for(auto it:arr)
        {
            if(it<0)
            neg.push_back(it);
            else
            pos.push_back(it);
        }
        
        
        int i=0;
        int j=0;
        bool now=false;
        int k=0;
        
        while(i<pos.size() && j<neg.size())
        {
            
            if(!now)
            {
                arr[k++]=pos[i++];
                
            }else
            {
                arr[k++]=neg[j++];
            }
            
            now=!now;
            
        }
        
        while(i<pos.size())
        {
             arr[k++]=pos[i++];
            
        }
        
        while(j<neg.size())
        {
            arr[k++]=neg[j++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends