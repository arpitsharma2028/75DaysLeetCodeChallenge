class Solution {
public:
    /*
    1. we have to detect cycle first -> if cycle exist then no answer is impossible
    2. if graph is Acyclic then do topological sort.

    One thing we can do, we can convert Edge List of graph to Adjacancy List
    to reduce Time complexity of Traversal from O(V.E) to O(V+E)
    Appraoch 1:
    1. Use Path Tracing method to detect cycle
    2. Use DFS + backtracking (push Current Element at end of Recusion) for Topological Sorting. 

    Approach 2:
    1.  Use Kahn Algorithm for Cycle Detection
        if no cycle Exist then return our sorted list
        if cycle exist then return empty array

    */
    bool dfs(int u ,vector<vector<int>>&graph , vector<bool>&vis , vector<bool>&recPath , stack<int>&s){ // detect cycle
        vis[u] = true;
        recPath[u] = true;
        for(auto v :  graph[u]){
            if(!vis[v]){
                if(dfs(v,graph , vis , recPath , s))return true;
            }else{
                if(recPath[v])return true;
            }
        }
        recPath[u] = false;
        s.push(u);
        return false;
    }

    vector<int>kahnSol(int V , vector<vector<int>>&graph){
        // calculate indegree
        // push node with indegree 0  in queue
        // reduce indegree of currently processing nodes, if indegree of neighbour of current is 0 then push them in queue
        
        vector<int>indeg(V,0);
        for(int u = 0 ; u < V ; u++){
            for(auto v : graph[u]){
                indeg[v]++;
            }
        }

        queue<int>q;
        for(int i = 0 ; i < V ; i++)if(!indeg[i])q.push(i);

        vector<int>topo;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for(auto v : graph[curr]){
                indeg[v]--;
                if(!indeg[v])q.push(v);
            }
        }
        if(topo.size() == V)return topo;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>>graph(V);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }
        // appraoch 1
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        stack<int>s;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i,graph,vis,recPath,s))return {};
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        // appraoch 2
        return kahnSol(V,graph);
    }
};