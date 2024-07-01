class Solution {
public:
    string removeStars(string st) {


        stack<char>s;


        for(auto it:st)
        {
            if(it=='*')
            {
                if(!s.empty())
                s.pop();
            }else
            {
                s.push(it);
            }
        }


        string ans="";

        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};