class Solution {
public:
    int appendCharacters(string s, string t) {

        int i=0;
        int j=0;
        int n=s.size();
        int m=t.size();

        int ans=0;

        while(i<n && j<m)
        {
            if(s[i]!=t[j])
            {i++;
                
            }else
            {
                i++,j++;
            }

        }

        if(j==m)
        return 0;
        else
        return m-j;
    
        
    }
};