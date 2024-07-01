//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<pair<int, int>> nextsmaller(const vector<int>& heights) {
    int n = heights.size();
    vector<pair<int, int>> ans(n, {INT_MAX, -1});
    stack<pair<int, int>> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= heights[i])
            s.pop();

        if (!s.empty())
            ans[i] = s.top();

        s.push({heights[i], i});
    }

    return ans;
}

vector<pair<int, int>> prevsmaller(const vector<int>& heights) {
    int n = heights.size();
    vector<pair<int, int>> ans(n, {INT_MAX, -1});
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= heights[i])
            s.pop();

        if (!s.empty())
            ans[i] = s.top();

        s.push({heights[i], i});
    }

    return ans;
}

vector<int> nearestSmallerTower(const vector<int>& arr) {
    vector<pair<int, int>> prev = prevsmaller(arr);
    vector<pair<int, int>> next = nextsmaller(arr);
    int n = arr.size();

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (prev[i].first == INT_MAX && next[i].first == INT_MAX) {
            ans[i] = -1;
        } else if (prev[i].first == INT_MAX) {
            ans[i] = next[i].second;
        } else if (next[i].first == INT_MAX) {
            ans[i] = prev[i].second;
        } else {
            int leftDist = i - prev[i].second;
            int rightDist = next[i].second - i;

            if (leftDist < rightDist) {
                ans[i] = prev[i].second;
            } else if (rightDist < leftDist) {
                ans[i] = next[i].second;
            } else {
                if (prev[i].first < next[i].first) {
                    ans[i] = prev[i].second;
                } else if (next[i].first < prev[i].first) {
                    ans[i] = next[i].second;
                } else {
                    ans[i] = min(prev[i].second, next[i].second);
                }
            }
        }
    }

    return ans;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends