class Solution {
  public:
  
  bool check(vector<int>&arr,int k,int mid)
  {
      int sum=0;
      
      for(auto it:arr)
      {
          sum+=(it+mid-1)/mid;
          if(sum>k)
          return false;
          
          
      }
      
      if(sum<=k)
      return true;
      else
      return false;
      
      
  }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(arr,k,mid))
            {
                high=mid-1;
                
            }else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};
