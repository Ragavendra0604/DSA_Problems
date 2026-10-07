class Solution {
public:
    // 1 & 2. Recursion and Memoiation
    // int helper(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
    //     if(i >= n){
    //         return 0;
    //     }

    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[i] + helper(i + 1, 0, n, prices, dp), 0 + helper(i + 1, 1, n, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[i] + helper(i + 2, 1, n, prices, dp), 0 + helper(i + 1, 0, n, prices, dp));
    //     }
    //     return profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // 3. Tabulation
        // vector<vector<int>> dp(n + 2, vector<int> (2, 0)); 

        // dp[n][0] = dp[n][1] = 0;
        // for(int i = n - 1 ; i >= 0 ; i--){
        //     for(int j = 0 ; j < 2 ; j++){
        //         if(j){
        //             dp[i][j] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
        //         }
        //         else{
        //             dp[i][j] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
        //         }
        //     }
        // }

        // return dp[0][1];


        // 4. Space Optmization
        vector<int> prev1(2, 0), prev2(2, 0), curr(2, 0);
        for(int i = n - 1 ; i >= 0 ; i--){
            curr[1] = max(-prices[i] + prev1[0], 0 + prev1[1]);
            curr[0] = max(prices[i] + prev2[1], 0 + prev1[0]);

            prev2 = prev1;
            prev1 = curr;
        }

        return curr[1];
    }
};