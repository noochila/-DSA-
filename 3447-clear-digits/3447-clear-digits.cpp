class Solution {
public:
    string clearDigits(string s) {
        
        
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                s[i]='+';
                int j=i-1;
                while(j>=0 && s[j]=='+')
                {
                   j--;
                }
                
                if(j>=0)
                s[j]='+';
                
            }
        }
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
         if(s[i]!='+')
            ans+=s[i];
        
        }
        
        return ans;
        
        
        
    }
};