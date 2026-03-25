class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            currMin = min(prices[i], currMin);
            profit = max(profit, prices[i] - currMin);
        }
        return profit;
    }
};