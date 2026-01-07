class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int currSum = 0;
        for(int st=0;st<n;st++){
            currSum += nums[st];
            maxSum = max(maxSum, currSum);
            if(currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};