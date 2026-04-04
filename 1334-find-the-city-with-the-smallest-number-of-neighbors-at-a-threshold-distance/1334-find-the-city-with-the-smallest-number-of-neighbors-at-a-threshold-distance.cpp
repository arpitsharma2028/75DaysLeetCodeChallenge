class Solution {
public:
    typedef pair<int,int> P;
    int dfs(vector<vector<P>>& graph ,  int src , int limit){
        // queue<P>q; // node , distance used
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
        };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);

        q.push({src,0});
        int V = graph.size();
        vector<int>dist(V,INT_MAX);
        dist[src] = true;
        int cnt = 0;
        while(!q.empty() ){
            int n = q.size();
            while(n--){
                int u = q.top().first;
                int CurrDist = q.top().second;
                q.pop();
                for(auto[v,wt] : graph[u]){
                    if(CurrDist + wt <= limit && CurrDist + wt < dist[v]){
                        if(dist[v] == INT_MAX)cnt++ ;
                        dist[v] = CurrDist + wt;
                        q.push({v, CurrDist + wt});
                    }
                }
            }
        }
        return cnt;
    }   
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<P>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        P A = {INT_MAX,-1}; // distance ,node 
        for(int i = 0 ; i < n ; i++){
            int cnt = dfs(adj , i, distanceThreshold);
            if(A.first >= cnt){
                A.first = cnt;
                A.second = i;
            }
        }
        return A.second;
    }
};