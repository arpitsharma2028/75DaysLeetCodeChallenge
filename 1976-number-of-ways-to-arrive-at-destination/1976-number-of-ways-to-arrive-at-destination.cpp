class Solution {
public:
    long long Dijkstra(vector<vector<pair<int,int>>> &adj , int n , int src , int dst){
        typedef pair<long long ,int>P;
        priority_queue<P , vector<P> , greater<P>> pq;
        long long mod = 1e9+7 ;

        vector<long long>cntPath(n,0);
        vector<long long>dist(n,LLONG_MAX);
        cntPath[src] = 1;
        dist[src] = 0;
        pq.push({0 , src});

        while(!pq.empty()){
            auto [currDist , u]  = pq.top();
            pq.pop();

            if(currDist > dist[u]) continue;
            for(auto [v , wt] : adj[u]){
                if(currDist + wt  <dist[v]){
                    dist[v] = currDist + wt;
                    pq.push({dist[v] , v});
                    cntPath[v] = cntPath[u];
                }else if(currDist + wt == dist[v]){
                    cntPath[v] = (cntPath[v] + cntPath[u]) % mod;
                }
            }
        }
        return cntPath[dst];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); 
        }
        return Dijkstra(adj, n, 0, n-1);
    }
};