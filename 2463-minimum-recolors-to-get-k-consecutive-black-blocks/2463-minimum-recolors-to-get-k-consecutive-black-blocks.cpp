class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n=blocks.size();
        int i=0;
        int j=0;
        int w=0;
        int b=0;
        int ans=1e9;

        while(j<n)
        {
            if(blocks[j]=='B')
            b++;
            else
            w++;
            if(j-i+1<k)
            j++;
            else{
                
                if(j-i+1==k)
                {

              ans=min(ans,w);
              if(blocks[i]=='B')
              b--;
              else
              w--;
              i++;
              j++;
                }
            }
            

        }
        return ans;
        
    }
};