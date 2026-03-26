class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // profit maximum => sell it when it have maximum amount and purchase it when price is low
        // also we can't sell before purchasing.
        int purchase = prices[0];
        int ans = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            ans = max(ans, prices[i]-purchase);
            purchase = min(purchase , prices[i]);
        }
        return ans;
    }
};