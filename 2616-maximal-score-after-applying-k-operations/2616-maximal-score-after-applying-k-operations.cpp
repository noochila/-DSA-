class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int>pq;
        
        for(auto i:nums)pq.push(i);
        
        long long ans = 0;
        for(int i = 0;i<k;i++)
        {
            int val = pq.top();
            ans+=val;
            pq.pop();
            pq.push(ceil(val*1.0/3.0));
        }
        return ans;
    }
};