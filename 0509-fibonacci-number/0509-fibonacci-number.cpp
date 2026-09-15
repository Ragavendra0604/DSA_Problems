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
    // int helper(int n, vector<int> &dp){
    //     if(n <= 1){
    //         return n;
    //     }
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = fib(n - 1) + fib(n - 2);
    // }
    // int fib(int n) {
    //     vector<int> dp(n + 1, -1);
    //     dp[n] = helper(n, dp);
    //     return dp[n];
    // }

    // 3. Tabulation
    // int fib(int n){
    //     if(n <= 1) return n;
    //     vector<int> dp(n+1, 0);
    //     dp[0] = 0, dp[1] = 1;
    //     for(int i = 2 ; i <= n ; i++){
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }

    // 4. Optimize Space to constant
    int fib(int n){
        if(n <= 1) return n;
        int prev2 = 0;
        int prev1 = 1;

        int curr = 0;
        for(int i = 2 ; i <= n ; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};