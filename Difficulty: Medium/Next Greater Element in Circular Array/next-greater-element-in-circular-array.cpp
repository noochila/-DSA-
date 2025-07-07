class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(arr[i]);
        }
        
        stack<int> s;
        
        vector<int> ans(n,-1);
        
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=arr[i])
            s.pop();
            
            if(!s.empty() && i<n)
            ans[i]=s.top();
            
            s.push(arr[i]);
            
        }
        
        return ans;
        
    }
};