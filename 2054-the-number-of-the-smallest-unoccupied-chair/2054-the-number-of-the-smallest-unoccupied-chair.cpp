class Solution {
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int arrival = times[targetFriend][0];
        priority_queue<P, vector<P>, greater<P>> pq;

        priority_queue<int, vector<int>, greater<int>> ids;

        sort(times.begin(), times.end());

        int chair = 0;

        for (auto it : times) {

            int at = it[0];
            int dp = it[1];

            while(!pq.empty() && pq.top().first<=at)
            {
                ids.push(pq.top().second);
                pq.pop();
            }

            if(ids.empty())
            {
                pq.push({dp,chair});
                if(arrival==at)
                {
                    return chair;
                }
                chair++;
            }else
            {
                int id=ids.top();
                ids.pop();
                if(arrival==at)
                return id;

                pq.push({dp,id});
            }

           
        }

        return 0;
    }
};