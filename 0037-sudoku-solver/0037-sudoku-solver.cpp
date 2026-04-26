class Solution {
public:
    bool isSafe(int row , int col ,char val ,vector<vector<char>>& board ){
        for(int i = 0 ; i < 9 ; i++){
            int sRow = (row/3)*3 + i/3;
            int sCol = (col/3)*3 + i%3;
            if(board[sRow][sCol] == val || board[row][i] == val || board[i][col] == val)return false;
        }
        return true;
    }
    bool helper(int row , int col,vector<vector<char>>& board , int n){
        if(col >= n)row++ , col = 0;
        if(row >= n )return true;
        if(board[row][col] != '.')return helper(row , col+1 , board , n);
        for(int i = 1 ; i <= 9 ; i++){
            char val = '0' + i;
            if(isSafe(row , col , val , board)){
                board[row][col] = val;
                if(helper(row, col+1 , board , n))return true;
                else
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>&board) {
        helper(0,0,board , board.size());
    }
};