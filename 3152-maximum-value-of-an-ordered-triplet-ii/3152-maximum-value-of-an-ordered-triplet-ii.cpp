class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
      
      int n=nums.size();

      vector<long long> prefix(n);
      vector<long long> maxi(n);

      prefix[1]=(nums[0]-nums[1]);
      maxi[0]=nums[0];


      for(int i=1;i<n;i++)
      maxi[i]=max(maxi[i-1],nums[i]*1ll);
      long long ans=0;


      for(int i=2;i<n;i++)
      {
        long long val=prefix[i-1];

        val=max(val,maxi[i-1]-nums[i]*1ll);

        prefix[i]=val;

        ans=max(ans,prefix[i-1]*nums[i]);

      }

      return ans;

        
    }
};