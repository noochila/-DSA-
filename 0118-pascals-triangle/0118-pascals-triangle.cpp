class Solution {
public:
    vector<int> solve(int i) {
        vector<int> temp;

        temp.push_back(1);
        int ans=1;

        // 1
        // 1 2 1
        // 1 3 3 1
        // 1 4 6 4 1

        for (int j = 1; j < i; j++) {

              ans*=(i-j);
              ans/=(j);
              cout<<ans<<" ";
              temp.push_back(ans);
        }

        cout<<endl;
        return temp;
    }

    vector<vector<int>> generate(int n) {

        vector<vector<int>> ans;

        for (int i = 1; i <= n; i++) {
            ans.push_back(solve(i));
        }
        return ans;
    }
};