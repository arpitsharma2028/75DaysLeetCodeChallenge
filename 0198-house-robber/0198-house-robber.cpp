class Solution {
public:
    int solveMemoization(vector<int>&nums  ,int i ,vector<int>&dp ){
        if(i>= nums.size() )return 0;
        if(dp[i] != -1)return dp[i];
        int steal = nums[i]+ solveMemoization(nums , i+2 , dp);
        int skip = solveMemoization(nums , i+1 , dp);
        dp[i] = max(steal , skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        // return  solveMemoization(nums , 0 , dp);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2 ; i <= nums.size() ; i++){
            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(steal , skip);
        }
        return dp[nums.size()];
    }
};