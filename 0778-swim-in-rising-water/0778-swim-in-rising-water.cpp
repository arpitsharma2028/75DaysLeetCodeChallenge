class Solution {
public:
    bool bfs(vector<vector<int>>&grid , int mid){
        if(grid[0][0] > mid)return false;
        int n = grid.size();
        vector<vector<bool>>vis(n , vector<bool> (n , false));
        auto isSafe = [&](int x , int y){
            return (x<n && y < n && x >= 0 && y>= 0);
        };
        vector<pair<int,int>>directions = {{1,0} , {-1 , 0} , { 0 , 1} , {0 , -1}};
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            for(auto [i,j] : directions){
                int x_ = x + i , y_ = y + j;
                if(isSafe(x_ , y_) && !vis[x_][y_] && grid[x_][y_] <= mid){
                    vis[x_][y_] = true;
                    q.push({x_ , y_});
                }
            }
        }
        return (vis[n-1][n-1]);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int st = 0 , end = INT_MIN, ans = -1 ;
        for(auto A : grid)
            for(auto B : A)end = max(end , B);
        
        while(st <= end){
            int mid = st + (end-st)/2;
            if(bfs(grid , mid)){
                end = mid-1;
                ans = mid;
            }else st = mid+1;
        }
        return ans;
    }
};