class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums)
        {
            sum += num;
        }
        if(sum & 1) return false;

        int target = sum / 2;

        vector<bool>dp(target + 1, false);
        dp[0] = true;

        for(int num:nums){
            for(int s = target ; s>=num ; s--){
                if(dp[s-num]){
                    dp[s] = true;
                }
            }
        }
        return dp[target];
    }
};