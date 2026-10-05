class Solution {
public:
    // 1. Recursion and then 2. Memoiation
    // int helper(int idx, int n, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     if(idx == n){
    //         return 0;
    //     }
    //     if(dp[idx][buy] != -1) return dp[idx][buy];
    //     int profit = 0;
    //     if(buy) {
    //         profit = max(-prices[idx] + helper(idx + 1, n, 0, prices, dp), 0 + helper(idx + 1, n, 1, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[idx] + helper(idx + 1, n, 1, prices, dp), 0 + helper(idx + 1, n, 0, prices, dp));
    //     }

    //     return dp[idx][buy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 2. Memoiation
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        
        // 3. Tabulation
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        // dp[n][0] = dp[n][1] = 0;

        // for(int i = n - 1 ; i >= 0 ; i--){
        //     int profit = 0;
        //     for(int j = 0 ; j < 2 ; j++){
        //         if(j) {
        //             profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
        //         }
        //         else{
        //             profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
        //         }
        //         dp[i][j] = profit;
        //     }
        // }

        // return dp[0][1];

        // 4. Space Optmization
        vector<int> prev(2, 0), curr(2, 0);
        prev[0] = prev[1] = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            int profit = 0;
            for(int j = 0 ; j < 2 ; j++){
                if(j) {
                    profit = max(-prices[i] + prev[0], 0 + prev[1]);
                }
                else{
                    profit = max(prices[i] + prev[1], 0 + prev[0]);
                }
                prev[j] = profit;
            }
            curr = prev;
        }

        return prev[1];
    }
};