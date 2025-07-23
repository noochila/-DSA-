class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        
        
        int sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            
            int left=(i+1);
            int right=(arr.size()-i);
            sum+=arr[i]*(right)*(left);
            

        }
        
        
        
        return sum;
        
        
        
    }
};