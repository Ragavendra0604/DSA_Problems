class Solution {
public:
    // 1 & 2 Recursion + Memoiation
    // int helper(int idx, int buy, int n, int cap, vector<int> & prices, vector<vector<vector<int>>> &dp){
    //     if(idx == n || cap == 0){
    //         return 0;
    //     }

    //     if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[idx] + helper(idx + 1, 0, n, cap, prices, dp), 0 + helper(idx + 1, 1, n, cap, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[idx] + helper(idx + 1, 1, n, cap - 1, prices, dp), 0 + helper(idx + 1, 0, n, cap, prices, dp));
    //     }
    //     return dp[idx][buy][cap] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));

        dp[n][0][0] = dp[n][1][1] = 0;
 
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                for(int k = 1 ; k <= 2 ; k++){
                    if(j){
                        dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], 0 + dp[i + 1][1][k]);
                    }
                    else{
                        dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], 0 + dp[i + 1][0][k]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};