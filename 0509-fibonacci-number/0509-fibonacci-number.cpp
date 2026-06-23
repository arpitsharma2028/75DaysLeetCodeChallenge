class Solution {
private:
    int fibb(int n, vector<int>& dp) { // Momoization Approach
        if (dp[n] != -1)
            return dp[n];
        if (n >= 2)
            dp[n] = (fibb(n - 1, dp) + fibb(n - 2, dp));
        return dp[n];
    }
    int fibTab(int n){ // tablulation approach
        if(n<2)return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++)dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
public:
    int fib(int n) {
        return fibTab(n); // tablulation approach
        
        if (n == 1 || n == 0)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return fibb(n, dp);
    }
};