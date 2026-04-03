class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        vector<pair<int,int>>adj[n];
        for(int i = 0 ; i < flights.size() ; i++){
            int u = flights[i][0], v = flights[i][1] , w = flights[i][2];
            adj[u].push_back({v,w});
        }
        typedef pair<int,int>P;
        queue<P>q;
        q.push({src,0});
        dist[src] = 0;
        int level = 0;
        while(!q.empty() && level <= k){
                int n = q.size();
                while(n--){
                    auto [u , currDist] = q.front();
                    q.pop();
                    for(auto [v , w] : adj[u]){
                        if(dist[v] > currDist + w){
                        dist[v] = min(dist[v] , currDist + w);
                        q.push({v , dist[v]});
                        }
                    }
                }
            level++;
        }
        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};