    class Solution {
    public:
    bool possible(int row,int col,char k,vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==k)
            return false;


            if(board[row][i]==k)
            return false;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==k)
                return false;  


        }

        return true;
        


    }

    bool check(vector<vector<char>> &board)
    {
 

 for(int i=0;i<9;i++)
 {
     for(int j=0;j<9;j++)
     {
         if(board[i][j]=='.')
         {
             for(char ch='1';ch<='9';ch++)
             {
                 if(possible(i,j,ch,board))
                 {
                     board[i][j]=ch;

                     if(check(board)==true)
                     return true;
                     else
                     board[i][j]='.';
                 }
                
             }
                  return false;
         }
     }
 }
 return true;
        
           
        

    }


        void solveSudoku(vector<vector<char>>& board) {

check(board);
            
            
        }
    };