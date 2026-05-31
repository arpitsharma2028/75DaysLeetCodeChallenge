class Solution {
public:
    // here edge is from b->a
    bool dfsSol(int src  , vector<vector<int>>& graph , vector<bool>&recPath , vector<int>&vis){
        vis[src] = true;
        recPath[src] = true;
        // how to traverse neighbour???
        // [u,v] => u--> then search for u in whole loop if we found u means we got its neighbour
        // here we have given [v,u]
        for(int i = 0 ; i < graph.size() ; i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!vis[v]){
                    if(dfsSol(v, graph , recPath , vis))return true;
                }
                else{
                    if(recPath[v])return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool>recPath(V,false);
        vector<int>vis(V,false);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfsSol(i,prerequisites,recPath ,vis))return false;
            }
        }
        return true;
    }
};