class Solution {
public:
    bool isCycleDFS(int u , vector<vector<int>>&graph ,  vector<bool>&vis , vector<bool>&inRec){
        inRec[u] = true;
        vis[u] = true;
        for(int v : graph[u]){
            if(!vis[v]){
                if(isCycleDFS(v,graph,vis,inRec))return true;
            }
            else{
                if(inRec[v])return true;
            }
        }
        inRec[u] =false;
        return false;
    }
    vector<int> dfsSol(vector<vector<int>>&graph){
        int V = graph.size();
        vector<bool>vis(V,false);
        vector<bool>inRec(V,false);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i])isCycleDFS(i,graph,vis,inRec);
        }
        vector<int>ans;
        for(int i = 0 ; i < V; i++)if(!inRec[i])ans.push_back(i);
        return ans;
    }
    vector<int>topoSort(vector<vector<int>>&graph , int V){
        vector<int>indeg(V,0);
        // 1. Indegree calculation
        for(int u = 0 ; u < V ; u++){
            for(int v : graph[u]){
                indeg[v]++;
            }
        }
        // 2. pushing 0 indegree in queue
        queue<int>q;
        for(int i = 0 ; i < V ;i++ )if(!indeg[i])q.push(i);

        // 3. Processing non cyclic nodes
        vector<int>ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for(int v : graph[u]){
                indeg[v]--;
                if(!indeg[v])q.push(v);
            }
        }
        // non cyclic nodes must be in ascending order as per demand of question
        sort(ans.begin(), ans.end());

        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        return dfsSol(graph);
        int V = graph.size();
        vector<vector<int>>adj(V);
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < graph[i].size() ; j++){
                int u = i;
                int v = graph[i][j];
                adj[v].push_back(u);
            }
        }
        return topoSort(adj , V);
    }
};