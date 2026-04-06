class Solution {
public:
    vector<int>par;
    vector<int>rank;
    void DSU(int n){
        par.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int findUltimatePar(int n){
        if(par[n] == n)return n;
        return par[n] = findUltimatePar(par[n]);
    }
    void unionByRank(int x , int y){
        int ParX = par[x] , ParY = par[y];
        if(rank[ParX] < rank[ParY]){
            par[ParX] =  ParY;
        }
        else if (rank[ParX] > rank[ParY]){
            par[ParY] = ParX;
        }else{
            rank[ParX]++ ;
            par[ParY] = ParX;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int comp = n;
        if (connections.size() < n-1)return -1;
        DSU(n);
        for(int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0] , v = connections[i][1];
            int ParU = findUltimatePar(u);
            int ParV = findUltimatePar(v);

            if(ParU != ParV){
                comp-- ;
                unionByRank(u,v);
            }
        }  
        return comp-1;
    }
};