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
    void bfs(int i , int j , vector<vector<char>>&graph,vector<vector<bool>>&vis){
        vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        int m = graph.size() , n = graph[0].size();
        auto isSafe =  [&](int x , int y){
            return (x >= 0 && y >= 0 && x < m && y < n);
        };

        // bfs -> queue -> src  -> push all its unvisited neighbours in it.
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = true;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto dir : directions){
                int x_ = dir[0];
                int y_ = dir[1];
                int x_neigh = x + x_;
                int y_neigh = y+y_;
                if(isSafe(x_neigh,y_neigh) && !vis[x_neigh][y_neigh] && graph[x_neigh][y_neigh] == '1'){
                    q.push({x_neigh,y_neigh});
                    vis[x_neigh][y_neigh] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,vis);
                    // dfs(i,j,grid , vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};