class DSU{
    vector<int>size;
    vector<int>par;
    public:
    DSU(int n){
        size.resize(n,1);
        par.resize(n);
        for(int i = 0 ; i < n ; i++)par[i] = i;
    }
    int findPar(int n)
    {
        if(par[n] == n)return n;
        return par[n] = findPar(par[n]);
    }
    void UNION(int x , int y){
        int parX = findPar(x) , parY = findPar(y);
        if(parX == parY)return ;
        if(size[parX] > size[parY]){
            par[parY] = parX;
            size[parX] += size[parY];
        }else{
            par[parX] = parY;
            size[parY] += size[parX];
        }
    }
    int findSize(int x){return size[x];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        DSU dsu(m*n);
        vector<pair<int,int>>directions =  { {1,0} , {-1 , 0} , {0,1} , {0,-1}};
        auto isSafe = [&](int x , int y){
            return (x<m && x >= 0 && y < n && y >= 0);
        };

        // making isLand
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int node = grid[i][j];
                int Node1 = i*n + j; 
                if(!node)continue;
                for(auto [x,y] : directions){
                    int x_ = i+x , y_ = j+y;
                    if(isSafe(x_ , y_) && grid[x_][y_]){
                        int Node2 = x_ * n + y_;
                        dsu.UNION(Node1 , Node2 );
                    }
                }
            }
        }

        int ans = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int node = grid[i][j];
                int Node1 = i*n + j; 
                unordered_set<int>s;
                for(auto [x,y] : directions){
                    int x_ = i+x , y_ = j+y;
                    if(isSafe(x_ , y_) && grid[x_][y_]){
                        int Node2 = x_ * n + y_;
                        s.insert(dsu.findPar(Node2));
                    }
                }
                int currIslands = 0;
                for(auto i : s)currIslands+= dsu.findSize(i);
                if(!node)currIslands+= 1;
                ans = max(currIslands , ans);
            }
        }
        return ans;
    }
};