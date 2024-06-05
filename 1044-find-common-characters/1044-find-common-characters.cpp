class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

    vector<int> min_f(26,1e9);


    for(int i=0;i<words.size();i++)
    {
         vector<int> f(26,0);
        for(auto it:words[i])
        {
         
            f[it-'a']++;
        }

        for(int j=0;j<26;j++)
        {
            min_f[j]=min(min_f[j],f[j]);
        }
    }


    vector<string> ans;

    for(int i=0;i<26;i++)
    {
        if(min_f[i]>0)
      {
          for(int j=0;j<min_f[i];j++)
          {
           ans.push_back(std::string(1, 'a' + i));

          }
      }
 
    }

    return ans;
        
    }
};