class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_max = 0;
        int total_min = INT_MAX;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            total_min = min(prices[i], total_min);
            total_max = max(prices[i]-total_min, total_max);
        }
        return total_max;
    }
};