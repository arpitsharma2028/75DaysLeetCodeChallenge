class Solution {
public:
    void bfs(vector<vector<int>>&image, int i , int j, int color){
        int m = image.size() , n = image[0].size();
        int prevCol = image[i][j];
        if(color == prevCol)return; // important to prevent TLE
        vector<vector<int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        auto isSafe =  [&](int x , int y){
            return (x >= 0 && y >= 0 && x < m && y < n);
        };
        queue<pair<pair<int,int> , int>>q; // node , its prev color;
        q.push({{i,j} , prevCol});
        image[i][j] = color;
        while(!q.empty()){
            int x_u = q.front().first.first;
            int y_u = q.front().first.second;
            prevCol = q.front().second;
            q.pop();

            for(auto dir : directions){
                int x_ = dir[0], y_ = dir[1];
                int x_v = x_u + x_ ;
                int y_v = y_u + y_ ;
                if(isSafe(x_v , y_v) && image[x_v][y_v] == prevCol){
                    image[x_v][y_v] = color;
                    q.push({{x_v , y_v} , prevCol});
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // M * N
        bfs(image , sr, sc , color); 
        return image;
    }
};