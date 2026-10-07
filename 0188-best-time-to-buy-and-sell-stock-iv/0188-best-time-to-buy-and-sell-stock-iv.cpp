class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));

        for(int i = 1 ; i <= k ; i++){
            dp[n][0][i] = dp[n][1][i] = 0;
        }
 
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                for(int z = 1 ; z <= k ; z++){
                    if(j){
                        dp[i][j][z] = max(-prices[i] + dp[i + 1][0][z], 0 + dp[i + 1][1][z]);
                    }
                    else{
                        dp[i][j][z] = max(prices[i] + dp[i + 1][1][z - 1], 0 + dp[i + 1][0][z]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};