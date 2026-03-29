class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>direction = {{0,1} , {1,0} , {-1,0} , {0,-1} , {1,1} , {-1,-1} , {1,-1} , {-1,1}};
        int m = grid.size() , n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1])return -1;
        typedef pair<int , pair<int,int>> P ;
        priority_queue<P , vector<P> , greater<P>>pq; // dist , {i,j};
        // queue<P>pq; // we can use queue too , as edge weight is same for all
        pq.push({0 , {0,0}});
        vector<vector<int>>dist(m , vector<int>(n , INT_MAX));
        dist[0][0] = 0;
        auto isSafe = [&](int x , int y){
            return (x >= 0 && y >= 0 && x < m && y < n); 
        };
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // perform edge relaxation for neighbours;
            for( auto dir : direction){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(x_ , y_) && !grid[x_][y_] && 1 + d < dist[x_][y_]){
                    dist[x_][y_] = 1 + d ;
                    pq.push({dist[x_][y_] , {x_ , y_}});
                }
            }

        }
        if(dist[m-1][n-1] == INT_MAX)
            return -1;
        
        return dist[m-1][n-1]+1;
    }
};