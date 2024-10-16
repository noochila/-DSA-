class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {

            auto temp=pq.top();
            pq.pop();

            if(ans.size()>=2 && ans[ans.size()-1]==temp.second && ans[ans.size()-2]==temp.second )
            {
                     
                     if(pq.empty())
                     return ans;
                     else
                     {
                        auto temp2=pq.top();
                        pq.pop();
                        ans+=temp2.second;
                        if(temp2.first-1>0)
                        pq.push({temp2.first-1,temp2.second});

                        pq.push(temp);

                        
                     }
            }else
            {
                ans+=temp.second;
                if(temp.first-1>0)
                pq.push({temp.first-1,temp.second});
            }

           
        }

        return ans;
    }
};