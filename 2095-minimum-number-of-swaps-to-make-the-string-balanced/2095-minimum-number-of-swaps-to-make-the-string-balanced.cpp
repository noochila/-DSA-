class Solution {
public:
    int minSwaps(string s) {

stack<char> st;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='[')
    st.push(s[i]);
    else 
    {
        if(!st.empty() && st.top()=='[')
        st.pop();
    }
}
if(st.size()==0)
return 0;

return (st.size()+1)/2;



    }
};