class Solution {
public:
    int helper(int idx, int buy, int n, int cap, vector<int> & prices, vector<vector<vector<int>>> &dp){
        if(idx == n || cap == 0){
            return 0;
        }

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + helper(idx + 1, 0, n, cap, prices, dp), 0 + helper(idx + 1, 1, n, cap, prices, dp));
        }
        else{
            profit = max(prices[idx] + helper(idx + 1, 1, n, cap - 1, prices, dp), 0 + helper(idx + 1, 0, n, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

        return helper(0, 1, n, 2, prices, dp);
    }
};