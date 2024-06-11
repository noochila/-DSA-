class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {


        vector<vector<int>>ans;

        int n=nums.size();

        for(int i=1;i<=pow(2,n);i++)
        {
            vector<int> temp;

            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }

            ans.push_back(temp);
        }
return ans;


        
    }
};