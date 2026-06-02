class Solution {
public:
    int minCost(int i , vector<int>&nums , vector<int>&dp){
        if(i >= nums.size())return 0;
        if(dp[i] != -1)return dp[i];
        int  oneStep = nums[i] + minCost(i+1 , nums , dp);
        int twoStep = nums[i] + minCost(i+2 , nums , dp);
        return dp[i] = min(oneStep , twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp1(n+2 , -1);
        vector<int>dp2(n+2 , -1);
        int ans = -1;
        return ans = min(minCost(0 , cost , dp1),minCost(1,cost , dp2));

    }
};