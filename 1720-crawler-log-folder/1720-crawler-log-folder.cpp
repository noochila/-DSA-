class Solution {
public:
    int minOperations(vector<string>& logs) {

     int c=0;
        for(auto i:logs) 
            c=max(0,c+(i[0]!='.'?1:i[1]=='.'?-1:0));
        return c;
    
        

    }
};