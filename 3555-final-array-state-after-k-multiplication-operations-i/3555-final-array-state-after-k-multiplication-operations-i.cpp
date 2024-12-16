class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }

        while(k--)
        {
            auto temp=pq.top();
            pq.pop();

            temp.first*=multiplier;
            // cout<<temp.first<<" "<<temp.second<<endl;
            pq.push(temp);
        }

        vector<int> ans(n);

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            ans[temp.second]=temp.first;
        }
        return ans;
        
    }
};