class Solution {
public:
    vector<int> nextGreater(vector<int>& heights) {
        int n = heights.size();

        vector<int> ans(n, n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            if (!s.empty())
                ans[i] = s.top();

            s.push(i);

               cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
    vector<int> prevGreater(vector<int>& heights) {
        int n = heights.size();

        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            if (!s.empty())
                ans[i] = s.top();

            s.push(i);

               cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> next = nextGreater(heights);
        vector<int> prev = prevGreater(heights);

        int maxi=0;
        int n=heights.size();


        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(-prev[i]+next[i]-1)*heights[i]);
        }

        return maxi;

        
    }
};