class Solution {
public:
    int prims(vector<vector<int>>&graph, int V){
        vector<bool>MST_SET(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq; // {dist,node}
        pq.push({0,0}); // node 0 , dist 0
        int cost = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if(!MST_SET[u]){
                cost+= dist;
                MST_SET[u] = true;
                for(int i = 0 ; i < V ; i++){
                    if(i == u)continue;
                    int wt = abs(graph[i][0] - graph[u][0]) + abs(graph[i][1] - graph[u][1]);
                    pq.push({wt , i});
                }
            }
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // basically i have nodes , and assume all nodes are connected to each and every nodes
        // i have to keep only those connections for which spanning tree is minimum.    
        int V = points.size();
        return prims(points , V);
    }
};