class Solution {
public:
    int helper(int i, int j1, int j2, int n, int m, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 > m){
            return -1e8;
        }

        if(i == n){
            if(j1 == j2) return mat[i][j1];
            else return mat[i][j1] + mat[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        long long maxi = 0;
        for(int d1 = -1 ; d1 <= 1 ; d1++){
            for(int d2 = -1 ; d2 <= 1 ; d2++){
                if(j1 == j2) maxi = max(maxi, (long long)mat[i][j1] + helper(i+1, j1 + d1, j2 + d2, n, m, mat, dp));
                else maxi = max(maxi, (long long)mat[i][j1] + (long long)mat[i][j2] + helper(i+1, j1 + d1, j2 + d2, n, m, mat, dp));
            }
        }

        return dp[i][j1][j2] = (int)maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

        return helper(0, 0, m - 1, n - 1, m - 1, grid, dp);
    }
};