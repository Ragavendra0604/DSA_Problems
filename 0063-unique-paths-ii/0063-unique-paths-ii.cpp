class Solution {
public:
    // long long helper(int i, int j, int n, int m, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
    //     if(obstacleGrid[n][m] == 1) return 0;
    //     if(i == n && j == m) return dp[i][j];

    //     if(i > n || j > m) return 0;

    //     if(obstacleGrid[i][j] == 1) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     long long right = helper(i, j + 1, n, m, obstacleGrid, dp);
    //     long long down = helper(i + 1, j, n, m, obstacleGrid, dp);

    //     return dp[i][j] = right + down;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0; 

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        dp[0][0] = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    long long down = (i > 0) ? dp[i - 1][j] : 0;
                    long long right = (j > 0) ? dp[i][j - 1] : 0;

                    dp[i][j] = right + down;
                }
            }
        }

        // long long count = helper(0, 0, n - 1, m - 1, obstacleGrid, dp);
        return dp[n - 1][m - 1];
    }
};