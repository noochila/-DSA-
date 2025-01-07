class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {


        set<string>s;
        int n=words.size();

        for(int i=0;i<words.size();i++)
        {
            string w=words[i];

            for(int j=0;j<i;j++)
            {
                if(words[j].find(w)!=string::npos)
                {
                    s.insert(w);
                }

            }
             for(int j=i+1;j<n;j++)
            {
                if(words[j].find(w)!=string::npos)
                {
                    s.insert(w);
                }

            }
        }

        return vector<string>(s.begin(),s.end());
        
    }
};