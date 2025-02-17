class Solution {
public:
    int numTilePossibilities(string tiles) {

        set<string>st;
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());

       do{

       
        for(int i=0;i<pow(2,n);i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    s.push_back(tiles[j]);
                    if(s.size()>=1)
                    st.insert(s);
                }
            }
        }
       }while(next_permutation(tiles.begin(),tiles.end()));

        // for(auto it:st)
        // cout<<it<<endl;

        return st.size();
        
    }
};