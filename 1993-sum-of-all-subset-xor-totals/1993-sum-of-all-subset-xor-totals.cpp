class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int n=nums.size();
        int ans=0;

        for(int i=1;i<=pow(2,n);i++)
        {
            vector<int>temp;

            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                temp.push_back(nums[j]);
            }

            int sum=0;
            for(int k=0;k<temp.size();k++)
            sum^=temp[k];

            ans+=sum;
        }
        return ans;
        
    }
};