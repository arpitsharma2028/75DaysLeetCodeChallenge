class Solution {
public:
    int solve(int left , int right , vector<int>&cuts,vector<vector<int>>&dp){
        if(right-left <= 1)return 0;
        if(dp[left][right] != -1)return dp[left][right];
        int ans = 1e9;
        for(int idx = left+1 ; idx <= right-1 ;idx++){
            int cost = cuts[right] - cuts[left] + solve(left , idx , cuts,dp) + solve(idx,right,cuts,dp);
            ans = min(ans,cost);
        }
        return dp[left][right] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int len = cuts.size();
        vector<vector<int>>dp(len , vector<int>(len,-1));
        return solve(0,cuts.size()-1 , cuts,dp);
    }
};