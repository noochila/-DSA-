class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long>mp;
        int n=segments.size();
        for(int i=0;i<n;i++){
            mp[segments[i][0]]+=segments[i][2];
            mp[segments[i][1]]-=segments[i][2];
        }
        long long color=0;
        int prev=-1;
        vector<vector<long long >>res;
        for(auto it :mp){
            if(prev!=-1 && color!=0){
                res.push_back({prev,it.first,color});
            }
            prev=it.first;
            color+=it.second;
        }
        return res;

        
    }
};