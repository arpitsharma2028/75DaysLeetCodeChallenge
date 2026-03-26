class Solution {
public:
    void dfs(int i , int j,vector<vector<char>>&graph , vector<vector<bool>>&vis){
        if(i<0 || j < 0 || i >=  graph.size() || j >= graph[0].size() || vis[i][j] || graph[i][j] == '0')return;
        vis[i][j] = true;

        // down
        dfs(i+1 , j , graph , vis);
        // right
        dfs(i , j+1 , graph , vis);
        // up
        dfs(i-1 , j , graph , vis);
        // left
        dfs(i , j-1 , graph , vis);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};