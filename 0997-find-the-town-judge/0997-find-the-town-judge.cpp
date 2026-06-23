class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // hints
        // Town judge trusts nobody => outdegree of town judge is 0

        vector<int>outDeg(n+1,0);
        for(auto v : trust){
            outDeg[v[0]]++;
        }
        int ans = -1;
        int cnt = 0;
        for(int i = 1 ; i < outDeg.size();i++)
            if(!outDeg[i]){
                ans = i;
                break;
            }
        
        // till now ans may be judge , according to 1st property , now we have to check for 2nd property
        if(ans == -1)return ans;
        vector<vector<int>>adjMat(n+1 , vector<int>(n+1 , 0));
        for(auto pairr : trust){
            int u = pairr[0] , v = pairr[1];
            adjMat[u][v] = 1;
        }
        for(int i = 1 ; i <= n ; i++){
            if(i == ans)continue;
            if(!adjMat[i][ans])
                return -1;
        }
        return ans;
    }
};