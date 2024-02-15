class Solution {
public:


    bool check(vector<int>& nums, int p,int k)
     

    {
         int n=nums.size();
         int pair=0;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]<=k)
            {
                pair++;
                i++;
            }

            if(pair==p)
            return true;
        }

        return false;

    }
    int minimizeMax(vector<int>& nums, int p) {

     int n=nums.size();
      sort(nums.begin(),nums.end());


      int low=0;
      int high= nums[n-1]-nums[0];

      int ans=0;

      while(low<=high)
      {
          int mid=(low+high)>>1;

          if(check(nums,p,mid))
          {
              ans=mid;
              high=mid-1;
              
          }else
          {low=mid+1;
              
          }


      }
        
        return ans;
    }
};