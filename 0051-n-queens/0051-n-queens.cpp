class Solution {
public:
vector<vector<string>> ans;


bool possible(int row,int col,vector<string>board,int n)
{
    int drow=row;
    int dcol=col;

    while(drow>=0 && dcol>=0)
    {
        if(board[drow][dcol]=='Q')
        return false;

        drow--;
        dcol--;
    }

    drow=row;
    dcol=col;

    while(drow>=0 && dcol>=0)
    {
            if(board[drow][dcol]=='Q')
        return false;
        dcol--;
    }

    drow=row;
    dcol=col;

    while(drow<n && dcol>=0)
    {
          if(board[drow][dcol]=='Q')
        return false;
        dcol--;
        drow++;
    }
    return true;



}



    void getQueens(vector<string>board,int col,int n)
    {

        if(col==n)
        {
            ans.push_back(board);
            return ;
        }


        for(int row=0;row<n;row++)
        {
             if(possible(row,col,board,n))
             {
                board[row][col]='Q';
                getQueens(board,col+1,n);
                board[row][col]='.';

             }
        }


    }

    vector<vector<string>> solveNQueens(int n) {

        string s(n,'.');
        vector<string> board;

        for(int i=0;i<n;i++)
        board.push_back(s);



        getQueens(board,0,n);
        return ans;

        
    }
};