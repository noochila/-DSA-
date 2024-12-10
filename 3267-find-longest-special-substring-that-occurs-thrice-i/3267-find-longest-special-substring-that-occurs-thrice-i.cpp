class Solution {
public:
    bool check(string str,string sub)
    {
   auto pos = str.find(sub, 0); // find first occurrence of sub
    int count = 0;

    while (pos != -1) {
        count++;
        if (count >= 3) {
            return true;
        }
        pos = str.find(sub, pos + 1); // find next occurrence of sub
    }

    return false;
    }
    
    int maximumLength(string s) {
        
        int i=0;
        int j=0;
        int len=-1;
        
        
        map<char,int> mp;
        
        int n=s.size();
        
        while(j<n)
        {
             mp[s[j]]++;
            if(mp.size()==1)
            {
                if(check(s,s.substr(i,j-i+1)))
                {
                    len=max(len,j-i+1);
                }
             }else
            {
                while(mp.size()!=0){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;}
            }
            
            j++;
       }
        
        return len;
        
        
        
        
        
        
        
        
    }
};