class Solution {
public:
    // 1 & 2. Recursion tree and memoiation
    // int helper(int i, int buy, int fee, int n, vector<int> &prices, vector<vector<int>> &dp){
    //     if(i == n){
    //         return 0;
    //     }
    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[i] + helper(i + 1, 0, fee, n, prices, dp), 0 + helper(i + 1, 1, fee, n, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[i] - fee + helper(i + 1, 1, fee, n, prices, dp), 0 + helper(i + 1, 0, fee, n, prices, dp));
    //     }
    //     return dp[i][buy] = profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // 3. Tabulation
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        // dp[n][0] = dp[n][1] = 0;
        // for(int i = n - 1 ; i >= 0 ; i--){
        //     for(int j = 0 ; j < 2 ; j++){
        //         if(j){
        //             dp[i][j] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
        //         }
        //         else{
        //             dp[i][j] = max(prices[i] - fee + dp[i + 1][1], 0 + dp[i + 1][0]);
        //         }
        //     }
        // }


        // 4. Space Optmization
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                if(j){
                    ahead[j] = max(-prices[i] + ahead[0], 0 + ahead[1]);
                }
                else{
                    ahead[j] = max(prices[i] - fee + ahead[1], 0 + ahead[0]);
                }
            }
            curr = ahead;
        }
        return ahead[1];
    }
};