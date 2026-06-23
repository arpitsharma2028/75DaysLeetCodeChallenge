class Solution {
public:
    int memoization(int idx , int prevIdx ,vector<int>&nums , vector<vector<int>>&dp){
        if(idx >= nums.size())return 0;
        if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx+1];
        int notTake = memoization(idx+1 , prevIdx , nums , dp);
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + memoization(idx+1 , idx , nums , dp);
        }
        return dp[idx][prevIdx+1] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return memoization(0,-1,nums,dp);
    }
};