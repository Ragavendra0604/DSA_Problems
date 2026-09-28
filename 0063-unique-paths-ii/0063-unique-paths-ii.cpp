class Solution {
public:
    long long helper(int i, int j, int n, int m, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(obstacleGrid[n][m] == 1) return 0;
        if(i == n && j == m) return dp[i][j];

        if(i > n || j > m) return 0;

        if(obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long right = helper(i, j + 1, n, m, obstacleGrid, dp);
        long long down = helper(i + 1, j, n, m, obstacleGrid, dp);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        long long count = helper(0, 0, n - 1, m - 1, obstacleGrid, dp);
        return -(int)count;
    }
};