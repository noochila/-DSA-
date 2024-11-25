class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {


        string start="";
        string target="";

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            start+=to_string(board[i][j]);
        }


        unordered_map<int,vector<int>>mp;

        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={3,1,5};
        mp[5]={4,2};

        target="123450";

        queue<string>q;
        q.push(start);
        int level=0;

        unordered_set<string>vis;
        
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto current=q.front();
                q.pop();
                int zeroidx=current.find('0');
                for(auto idx:mp[zeroidx])
                {
                    string temp=current;
                    if(temp==target)
                    return level;
                    swap(temp[idx],temp[zeroidx]);

                    if(vis.find(temp)==vis.end())
                    {
                        vis.insert(temp);
                        q.push(temp);
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
};