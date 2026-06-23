class Solution {
private:
    int solveMemoization(vector<int>&nums  ,int i ,vector<int>&dp , int n ){
        if(i >= n )return 0;

        if(dp[i] != -1)return dp[i];
        int steal = nums[i] + solveMemoization(nums , i+2 , dp , n);
        int skip = solveMemoization(nums , i+1 , dp , n);
        dp[i] = max(steal , skip);
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        // we know how to solve linear version of this problem
        // now there is only 1 twist , if i rob 1st then cann't rob last , and if i rob last then can't rob 1st.

        int n = nums.size();
        if(n==1)return(nums[0]);
        vector<int>dp(n+1 , -1);
        int inclFirst = solveMemoization(nums , 0 , dp , n-1);
        for(int i = 0 ; i < dp.size() ; i++)dp[i] = -1;
        int ExclFirst =  solveMemoization(nums , 1 , dp , n);
        return max(inclFirst,ExclFirst);
    }
};