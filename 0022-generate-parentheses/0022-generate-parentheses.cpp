class Solution {
public:

   vector<string>ans;

   void solve(int forward,int  backward,string s)
   {
   
      if(backward==0)
    {
        ans.push_back(s);
        return ;
    }
   
    if(forward>0)
    solve(forward-1,backward,s+'(');

    if(forward<backward)
    solve(forward,backward-1,s+')');

             
   }



    vector<string> generateParenthesis(int n) {




     string s="";
     int forward=n;
     int backward=n;

     solve(forward,backward,s);
     return ans;



        
    }
};