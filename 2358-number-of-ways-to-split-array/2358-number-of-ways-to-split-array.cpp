class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n=nums.size();
        vector<long long>prefix(n+1,0);
        vector<long long>suffix(n+2,0);

        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=n;i>=1;i--)
        {
            suffix[i]=suffix[i+1]+nums[i-1];
        }

        int c=0;
        for(int i=1;i<n;i++)
        {
            if(prefix[i]>=suffix[i+1])
            c++;

        }
        return c;


        
    }
};