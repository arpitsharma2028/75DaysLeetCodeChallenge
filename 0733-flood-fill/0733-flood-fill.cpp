class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& graph,vector<vector<bool>>& vis, int col , int m , int n){
        if(i < 0 || j < 0 || i >= m || j >= n || graph[i][j] != col || vis[i][j])return;
        
        vis[i][j] = true;

        if(i+1 < m){
            graph[i+1][j] = col;
            dfs(i+1,j,graph,vis,col,m,n);
        }
        if(i-1 >= 0 ){
            graph[i-1][j] = col;
            dfs(i-1,j,graph,vis,col,m,n);
        }
        if(j+1 < n){
            graph[i][j+1] = col;
            dfs(i,j+1,graph,vis,col,m,n);
        }
        if(j-1 >= 0){
            graph[i][j-1] = col;
            dfs(i,j-1,graph,vis,col,m,n);
        }

    }
    void bfs(vector<vector<int>>&image, int i , int j, int color , vector<vector<bool>>&vis){
        int m = image.size() , n = image[0].size();
        vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        auto isSafe =  [&](int x , int y){
            return (x >= 0 && y >= 0 && x < m && y < n);
        };
        queue<pair<pair<int,int> , int>>q; // node , its prev color;
        int prevCol = image[i][j];
        q.push({{i,j} , prevCol});
        vis[i][j] = true;
        image[i][j] = color;
        while(!q.empty()){
            int x_u = q.front().first.first;
            int y_u = q.front().first.second;
            prevCol = q.front().second;
            // image[x_u][y_u] = color;
            q.pop();

            for(auto dir : directions){
                int x_ = dir[0], y_ = dir[1];
                int x_v = x_u + x_ ;
                int y_v = y_u + y_ ;
                if(isSafe(x_v , y_v) &&  !vis[x_v][y_v] && image[x_v][y_v] == prevCol){
                    image[x_v][y_v] = color;
                    q.push({{x_v , y_v} , prevCol});
                    vis[x_v][y_v] = true;
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // M * N
        int m = image.size() , n = image[0].size();
        // image[sr][sc] = color;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        bfs(image , sr, sc , color , vis); 
        return image;
        dfs(sr,sc,image,vis,color,m,n);
        return image;
    }
};