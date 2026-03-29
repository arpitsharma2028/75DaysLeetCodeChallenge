class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{0,1} , {1,0} , {-1,0} , {0,-1}};
        int m = heights.size() , n = heights[0].size();
        auto isValidMove = [&](int x , int y){
            return (x>= 0 && y >= 0 && x < m && y < n);
        };

        typedef pair<int,pair<int,int>> P;
        priority_queue<P, vector<P> , greater<P>>pq;
        pq.push({0 , {0,0}}); // dist , src
        vector<vector<int>>dist(m , vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            int x = curr.second.first , y = curr.second.second;
            pq.pop();
            for(auto dir : directions){
                int x_ = dir[0]+x;
                int y_ = dir[1]+y;
                if(isValidMove(x_ , y_) && max(dist[x][y] , abs(heights[x][y] - heights[x_][y_])) < dist[x_][y_]){
                   dist[x_][y_] =  max(dist[x][y] , abs(heights[x][y] - heights[x_][y_]));
                   pq.push({dist[x_][y_] , {x_ , y_}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};