class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int ans=0;

        for(int i=0,r=people.size()-1;i<=r;r--)
        {
            if(people[i]+people[r]<=limit)
            i++;
            ans++;
        }

        return ans;
        
    }
};