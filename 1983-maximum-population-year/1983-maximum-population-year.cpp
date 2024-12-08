class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        

        vector<int> a(2060);
        for(auto it:logs)
        {
            a[it[0]]+=1;
            a[it[1]]-=1;
        }

        for(int i=1;i<=2050;i++)
        a[i]+=a[i-1];


        return max_element(a.begin(),a.end())-a.begin();
    }
};