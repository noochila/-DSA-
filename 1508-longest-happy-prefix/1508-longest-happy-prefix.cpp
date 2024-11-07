class Solution {

public:

vector<int> LPS;

    string buildtable(string& s)
    {
        int n=s.size();
        LPS.resize(n,0);
        int i=1;
        int len=0;
        while(i<n)
        {
            if(s[i]==s[len] )
            {
                len++;
                LPS[i]=len;
                i++;
            }else if(len!=0)
            {
                len=LPS[len-1];
            }else
            {
                LPS[i]=0;
                i++;
            }
        }

     
        return s.substr(0,LPS.back());

    }


    string longestPrefix(string s) {

        return buildtable(s);
        
    }
};