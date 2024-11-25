class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {

        priority_queue<int> avail;
        priority_queue<int,vector<int>,greater<int>>apply;
        int success=0;

        sort(q.begin(),q.end());

        int idx=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(idx<q.size() && q[idx][0]==i)
            {
                avail.push(q[idx][1]);
                idx++;
            }

            nums[i]-=apply.size();

            while(nums[i]>0 && !avail.empty() && avail.top()>=i)
            {
                success++;
                apply.push(avail.top());
                avail.pop();
                nums[i]--;

            }

            if(nums[i]>0)
            return -1;

            while(!apply.empty() && apply.top()==i)
            {
                apply.pop();
            }


        }

        return q.size()-success;
        
        
    }
};