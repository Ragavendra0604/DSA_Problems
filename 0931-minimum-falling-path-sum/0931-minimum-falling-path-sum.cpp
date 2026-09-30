class Solution {
public:
    // long long helper(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    //     if(j < 0 || j >= m) return INT_MAX;
    //     if(i == n - 1) return mat[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     long long left = helper(i + 1, j - 1, n, m, mat, dp);
    //     long long mid = helper(i + 1, j, n, m, mat, dp);
    //     long long right = helper(i + 1, j + 1, n, m, mat, dp);

    //     return dp[i][j] = mat[i][j] + min({left, mid, right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp = matrix;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] += min({up, left, right});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};