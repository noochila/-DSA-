class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        long long count = 0;
        int n = nums.size();

        //  for(int i=0;i<n;i++)
        //  {
        //     int maxi=-1e9;
        //     int mini=1e9;
        //     for(int j=i;j<n;j++)
        //     {
        //         maxi=max(maxi,nums[j]);
        //         mini=min(mini,nums[j]);
        //         if(abs(maxi-mini)<=2)
        //         {
        //               count++;
        //         }

        //     }
        //  }

        int i = 0;
        int j = 0;
        deque<int> maxi;
        deque<int> mini;
        while (j < n) {

            while (!maxi.empty() && maxi.back() < nums[j])
                maxi.pop_back();

            maxi.push_back(nums[j]);

            while (!mini.empty() && mini.back() > nums[j])
                mini.pop_back();

            mini.push_back(nums[j]);

            while (i < j && abs(maxi.front() - mini.front()) > 2) {

                if (nums[i] == maxi.front()) {
                    maxi.pop_front();
                }

                if (nums[i] == mini.front()) {
                    mini.pop_front();
                }
                i++;

            }


             count+=(j-i+1);
            // cout<<count<<" "<<maxi.front()<<" "<<mini.front()<<endl;
            j++;
        }

        return count;
    }
};