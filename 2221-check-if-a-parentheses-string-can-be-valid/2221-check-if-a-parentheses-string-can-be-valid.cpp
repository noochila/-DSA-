class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>open;
        stack<int>unlock;
        int n=s.size();
        if(n%2)
        return false;

        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            unlock.push(i);
            else if(s[i]=='(')
            open.push(i);
            else
            {
                if(!open.empty())
                {
                    open.pop();
                }else if(!unlock.empty())
                {
                    unlock.pop();
                }else
                {
                    return false;
                }
            }
        }

        while(!open.empty() && !unlock.empty())
        {
            if(open.top()<unlock.top())
            {
                open.pop();
                unlock.pop();
            }else
            {
                return false;
            }
        }
        if(open.empty())
        return true;
        else
        return false;
        
    }
};