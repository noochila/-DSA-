class Solution {
public:
    
      long long check(vector<int>&piles,int val)
      {
           long long ans=0;
          
          for(auto it:piles)
          {
              ans+=ceil((double)it/(double)val);
          }
          return ans;
      }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            
            if(check(piles,mid)<=h)
            {
                ans=mid;
                high=mid-1;
           }
            else
                low=mid+1;
        }
        
        return low;
    }
};