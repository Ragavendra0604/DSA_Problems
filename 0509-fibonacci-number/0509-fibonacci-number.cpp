class Solution {
public:
    // 1. Recursion
    // int fib(int n) {
    //     if(n <= 1){
    //         return n;
    //     }

    //     return fib(n - 1) + fib(n - 2);
    // }
    
    // 2. Memoization
    int helper(int n, vector<int> &dp){
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n - 1) + fib(n - 2);
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        dp[n] = helper(n, dp);
        return dp[n];
    }
};