class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int i=0;
        int j=0;
        int n=nums.size();
        long long sum=0;
        long long ans=0;
        while(j<n)
        {

            sum+=nums[j];

            while(i<=j && sum*(j-i+1)>=k)
            {
                sum-=nums[i];
                i++;
            }

            ans+=(j-i+1);
            j++;

        }
        return ans;
        
    }
};