class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>st;
        st.push(-1); //considering that after that index valid paranthesis starts
        int maxi=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            st.push(i);
            else
            st.pop();

            if(st.empty())
            st.push(i);//consdering the string till i is invalid
            else
            {
                maxi=max(maxi,i-st.top());

            }
        }

        return maxi;
        
    }
};