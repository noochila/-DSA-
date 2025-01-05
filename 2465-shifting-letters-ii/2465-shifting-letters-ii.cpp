class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {


        int n=s.size();
        vector<int> temp(n+2,0);
        for(auto it:shifts)
        {
            int l=it[0];
            int r=it[1];
            int d=it[2];
            if(d)
            {
                temp[l]++;
                temp[r+1]--;
            }else
            {
                temp[l]--;
                temp[r+1]++;
            }
        }

        for(int i=1;i<n;i++)
        temp[i]+=temp[i-1];

        for(int i=0;i<n;i++)
        {
            int currval=s[i]-'a';
            int t=(currval+(temp[i]%26+26)%26);
            if(t<0)
            t+=26;
            int newval=(t)%26;
            
            s[i]=(newval+'a');
        }
        return s;


        
    }
};