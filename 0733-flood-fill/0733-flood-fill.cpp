class Solution {
public:
    void Traversal(vector<vector<int>>&graph, int sr, int sc, int color,vector<vector<bool>>& vis , int m , int n , int color2){
        if(sr >= m || sc >= n || sc < 0 || sr < 0 || vis[sr][sc])return;
        vis[sr][sc] = true;
        // updation
        if(graph[sr][sc] == color){
        if(sc+1<n && graph[sr][sc+1] == color2){ graph[sr][sc+1] = color; } // right
        if(sr+1< m && graph[sr+1][sc] == color2){ graph[sr+1][sc] = color; } // bottom
        if(sc-1 >= 0 && graph[sr][sc-1] == color2){ graph[sr][sc-1] = color; } // left
        if(sr-1 >= 0 && graph[sr-1][sc] == color2){ graph[sr-1][sc] = color; } // top
        // recursive calls
        
        Traversal(graph,sr , sc+1, color , vis , m,n , color2); // right
        Traversal(graph, sr+1 , sc ,color , vis , m,n , color2); // bottom
        Traversal(graph, sr ,sc-1,color , vis , m,n , color2); // left
        Traversal(graph, sr-1 , sc,color , vis , m,n , color2); // top
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int temp = color;
        color = INT_MAX;
        int m = image.size() , n = image[0].size(), color2 = image[sr][sc];
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        image[sr][sc]=  color;
        Traversal(image , sr , sc , color ,vis,m , n , color2);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(image[i][j] == INT_MAX)image[i][j] = temp;
            }
        }
        return image;
    }
};