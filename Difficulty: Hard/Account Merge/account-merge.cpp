//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Disjointset
{
    public:
    vector<int> rank,parent,size;
    Disjointset(int n)
    {
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
        parent[i]=i;

    }
    int findUpar(int u)
    {
        if(parent[u]==u)
        return u;
        return parent[u]=findUpar(parent[u]);
    }

    void unionByrank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)
        return ;

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;

        }else{
             parent[ulp_v]=ulp_u;
             rank[ulp_u]++;

        }
    }

    void unionBysize(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)
        return ;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
             parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];

        }
        
    }

};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
         Disjointset ds(accounts.size());
        
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            
            
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp[accounts[i][j]]=i;
                    
                }else
                {
                    ds.unionBysize( mp[accounts[i][j]],i);
                }
            }
        }
        
        vector<string> ans[accounts.size()];
        
        for(auto it:mp)
        {
            
            ans[ds.findUpar(it.second)].push_back(it.first);
            
        }
        
        vector<vector<string>> fans;
        
        
        for(int i=0;i<accounts.size();i++)
        {
            if(ans[i].size()==0)
            continue;
            
            sort(ans[i].begin(),ans[i].end());
            
            vector<string> temp;
            
            temp.push_back(accounts[i][0]);
            
            for(auto it:ans[i])
            temp.push_back(it);
            
            fans.push_back(temp);
        }
        
        return fans;
        
        
        
        
       
        
       
        
        
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends