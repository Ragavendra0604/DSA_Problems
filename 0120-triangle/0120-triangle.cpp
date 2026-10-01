class Solution {
public:
    // int helper(int i, int j, int n, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    //     if(i == n) return triangle[i][j];

    //     if(i > n || j > m) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = triangle[i][j] + helper(i + 1, j, n, m, triangle, dp);
    //     int right = triangle[i][j] + helper(i + 1, j + 1, n, m, triangle, dp);

    //     return dp[i][j] = min(down, right);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0 ; j < m; j++){
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                int down = triangle[i][j] + dp[i + 1][j];
                int right = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, right);
            }
        }

        return dp[0][0];
    }
};