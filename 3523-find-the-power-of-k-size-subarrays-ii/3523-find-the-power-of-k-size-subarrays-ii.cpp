class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int i=0;
        int j=0;
        int n=nums.size();

        deque<int>q;
        vector<int>ans;

        int ind=-1;
        bool sort=true;


         while(j<n)
         {
            if(!q.empty() && q.back()+1!=nums[j])
            {
                sort=false,ind=j;

            }

            q.push_back(nums[j]);
            if(j-i+1==k)
            {
                if(sort)
                ans.push_back(q.back());
                else
                ans.push_back(-1);


                q.pop_front();
                i++;
                if(ind>i && ind<=j)
                sort=false;
                else
                sort=true;
            }
            j++;
         }
         return ans;


    }
};
