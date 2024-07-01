class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char,int>freq;
        unordered_map<char,bool> taken;

        for(auto it:s)
        freq[it]++;

        string ans="";

        for(auto it:s)
        {
           if(taken[it])
           {
            freq[it]--;
              continue;
           }


           while(ans.size()>0 && ans.back()>it && freq[ans.back()]>0)
           {
             
                   taken[ans.back()]=false;
                   ans.pop_back();
               
           }

           ans.push_back(it);
           taken[it]=true;
           freq[it]--;
        }


        return ans;


        
    }
};