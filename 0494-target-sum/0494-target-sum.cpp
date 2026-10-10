class Solution {
public:
    // 1 & 2. Recursion + Memoization
    int helper(int idx, int sum, int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(idx == n){
            return (sum == target) ? 1 : 0;
        }
        
        int key = sum + 1000;
        if(dp[idx][key] != -1) return dp[idx][key];

        int add = helper(idx + 1, sum + nums[idx], n, target, nums, dp);

        int subtract = helper(idx + 1, sum - nums[idx], n, target, nums, dp);

        return dp[idx][key] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (2001, -1));

        return helper(0, 0, n, target, nums, dp);
    }
};