class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        queue<pair<string,int>>  q;

        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);


        while(!q.empty())
        {

            auto temp=q.front();
            q.pop();

            if(temp.first==endWord)
            return temp.second;


            for(int i=0;i<temp.first.size();i++)
            {
                  char c=temp.first[i];
                for(auto ch='a';ch<='z';ch++)
                {
                  temp.first[i]=ch;
                  if(s.find(temp.first)!=s.end())
                  {
                    q.push({temp.first,temp.second+1});
                    s.erase(temp.first);
                  }

                }
                temp.first[i]=c;
            }
        }

        return 0;
        
    }
};