class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {


        int n=nums.size();


        vector<int> prefix(n);
        

        map<int,int>mp;

        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            prefix[i]=sum;

            if(i+1>1 && sum%k==0)
            return true;

            if(mp.find(sum%k)!=mp.end())
            {
                int len=i-mp[sum%k];
                if(len>1)
                return true;
            }else
            {
                mp[sum%k]=i;
            }

        }

        return false;



        
    }
};