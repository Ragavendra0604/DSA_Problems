class Solution {
public:
    // int helper(int n, vector<int> &dp) {
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;
        
    //     if (dp[n] != -1) return dp[n];
    //     return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    // }
    int climbStairs(int n) {
        // if(n < 0){
        //     return 0;
        // }
        // if(n == 1){
        //     return 1;
        // }

        // if(n == 2){
        //     return 2;
        // }
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // 1. Memoization
        // vector<int> dp(n + 1, -1);
        // return helper(n, dp);

        // 2. Tabulation
        // vector<int> dp(46);

        // dp[0] = 0, dp[1] = 1, dp[2] = 2;

        // for(int i = 3 ; i <= n ; i++){
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }

        // return dp[n];

        // 3. Space Optmization
        if( n <= 2){
            return n;
        }
        int first = 1;
        int second = 2;

        for(int i = 3 ; i <= n ; i++){
            int next = first + second;
            first = second;
            second = next;
        }
        return second;
    }
};