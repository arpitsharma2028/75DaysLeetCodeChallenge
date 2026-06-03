class Solution {
public:
    int fibb(int n , vector<int> &dp){
    if( dp[n] != -1)return dp[n];
    if(n>=2)
    dp[n] = (fibb(n-1 , dp )+ fibb(n-2  ,dp ));
    return dp[n];
}
int fib(int n) {
    if(n == 1 || n== 0)return n;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    return fibb(n , dp);
    }
};