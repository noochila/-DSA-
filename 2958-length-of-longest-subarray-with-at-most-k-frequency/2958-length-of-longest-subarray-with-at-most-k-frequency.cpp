class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int len=0;
        int n=nums.size();

        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]<=k)
            {
                len=max(len,j-i+1);
                j++;
            }
            else
            {
                while( i<n && mp[nums[j]]>k)
                {
                    mp[nums[i]]--;
                    i++;
                }
                j++; // Increment j inside the else block
            }
        }
        return len;
    }
};
