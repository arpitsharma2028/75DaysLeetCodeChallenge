class Solution {
public:
    bool isSafe(int i , int j , int n , vector<string>&board){
        int row = i , col = j;
        while(row>= 0 && col >= 0){ // check upper diagonal
            if(board[row][col] == 'Q')return false;
            row-- , col--;
        }
        row = i , col = j;
        while(col>=0){
            if(board[row][col] == 'Q')return false;
            col--;
        }
        row = i , col = j;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void helper(int col,vector<string>&board,vector<vector<string>>&ans , int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row  < n ; row ++){ // filling row wise
            if(isSafe(row ,col , n , board)){
                board[row][col] = 'Q';
                helper(col+1,board , ans , n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str;
        for(int i = 0 ; i < n ; i++)str.push_back('.');
        vector<string>board(n,str);
        helper(0,board,ans, n);
        return ans;
    }
};