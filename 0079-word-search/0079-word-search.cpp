class Solution {
    private: pair<int,int> checking(int row,int col,vector<vector<char>>&board,int count,string word)
    {
   
    
           int drow=row;
           int dcol=col-1;

           if((drow>=0 && drow<board.size())  && (dcol>=0 && dcol<board[0].size()))
           {
               if(word[count]==board[drow][dcol])
               {
                    cout<<"l";
                     return {drow,dcol};
                      
               }
             
           }

           drow=row;
           dcol=col+1;

           if((drow>=0 && drow<board.size())  && (dcol>=0 && dcol<board[0].size()))
           {
               if(word[count]==board[drow][dcol])
               {
                 cout<<"m";
                   return {drow,dcol};
               }
           }

           drow=row-1;
           dcol=col;
            if((drow>=0 && drow<board.size())  && (dcol>=0 && dcol<board[0].size()))
           {
               if(word[count]==board[drow][dcol])
               {
               cout<<"n";
                   return {drow,dcol};
               }
           }

           drow=row+1;
           dcol=col;
            if((drow>=0 && drow<board.size())  && (dcol>=0 && dcol<board[0].size()))
           {
               if(word[count]==board[drow][dcol])
               {
                cout<<"o";
                   return {drow,dcol};
               }
           }

       return {-1,-1};

           
        
    }

private:
  bool check(int k,int i,int j,int n,vector<vector<char>>&board,string word)
  {
      if(k==n)
      {
          return true;

      }
          if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[k])
          return false;

          char ch=board[i][j];
          board[i][j]='#';


          bool bool1=check(k+1,i+1,j,n,board,word);
          bool bool2=check(k+1,i,j+1,n,board,word);
          bool bool3=check(k+1,i-1,j,n,board,word);
          bool bool4=check(k+1,i,j-1,n,board,word);
              board[i][j]=ch;



      return bool1 ||bool2 ||bool3||bool4;

  }

public:
    bool exist(vector<vector<char>>& board, string word) {

       for(int row=0;row<board.size();row++)
       {
           for(int col=0;col<board[0].size();col++)
           {
               if(check(0,row,col,word.size(),board,word))
               return true;
           }
       }
       

     return false; 
    }

    
};