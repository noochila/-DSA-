//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        
        
        vector<double>ans;
        
        
        priority_queue<int,vector<int>,greater<int>>minheap;
        priority_queue<int>maxheap;
        
        for(int i=0;i<arr.size();i++)
        {
            if(maxheap.size()==0 || maxheap.top()>arr[i])
           maxheap.push(arr[i]);
           else
           minheap.push(arr[i]);
           
           if(maxheap.size()>minheap.size()+1)
           {
               minheap.push(maxheap.top());
               maxheap.pop();
           }else if(minheap.size()>maxheap.size())
           {
               
               maxheap.push(minheap.top());
               minheap.pop();
               
               
           }
           
           if(maxheap.size()>minheap.size())
           {
               ans.push_back(maxheap.top());
           }else
           {
               ans.push_back((double(maxheap.top())+double(minheap.top()))/2.0);
           }
           
          
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends