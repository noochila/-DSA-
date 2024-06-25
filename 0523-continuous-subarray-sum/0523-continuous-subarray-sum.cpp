class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        

        int n=nums.size();
        int sum=0;
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            if(sum%k==0 && i+1>1)
            return true;

            if(mp.find(sum%k)!=mp.end())
            {
                int len=i-mp[sum%k];
                if(len>1)
                return true;
            }


           if(mp.find(sum%k)==mp.end())
            mp[sum%k]=i;

        }
        return false;
    }
};