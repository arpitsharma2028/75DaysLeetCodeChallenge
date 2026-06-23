class Solution {
public:
    int getSum(int n){
        int ans = 0;
        while(n){
            ans+= n%10;
            n/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto i : nums)ans = min(ans , getSum(i));
        return ans;
    }
};