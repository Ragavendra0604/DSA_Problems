class Solution {
public:
    // 1. Recursion
    // int helper(int idx, vector<int> &nums){
    //     if(idx == 0) return nums[idx];

    //     if(idx < 0) return 0;

    //     int pick = nums[idx] + helper(idx - 2, nums);

    //     int nopick = 0 + helper(idx - 1, nums);

    //     return max(pick, nopick);
    // }

    // 2. Memoization
    // int helper(int idx, vector<int> &nums, vector<int> &dp){
    //     if(idx == 0) return nums[idx];

    //     if(idx < 0) return 0;

    //     if(dp[idx] != -1) return dp[idx];

    //     int pick = nums[idx] + helper(idx - 2, nums, dp);

    //     int nopick = 0 + helper(idx - 1, nums, dp);

    //     return dp[idx] = max(pick, nopick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // 2. Memoization
        // vector<int> dp(n + 1, -1);
        // int maxMoney = helper(n - 1, nums, dp);

        // return dp[n - 1];
        
        // 3. Tabulation
        vector<int> dp(n); 

        dp[0] = nums[0];
        int neg = 0;

        for(int i = 1 ; i < n ; i++){
            int pick = nums[i]; if(i > 1) pick += dp[i - 2];
            int notpick = 0 + dp[i - 1];

            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
};