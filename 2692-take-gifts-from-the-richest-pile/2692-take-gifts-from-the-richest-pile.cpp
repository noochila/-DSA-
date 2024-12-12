class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>pq;

        for(auto it:gifts)
        pq.push(it);


        while(k--)
        {
            int maxi=pq.top();
            pq.pop();
            int ans=sqrt(maxi);
            pq.push(ans);
        }

        long long ans=0;
        while(!pq.empty())
        {
            ans+=(pq.top());
            pq.pop();
        }
        return ans;
        

    }
};