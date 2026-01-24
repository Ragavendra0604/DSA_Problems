class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;

        int maxSum = 0;
        while(left <= right){
            int sum = nums[left] + nums[right];
            maxSum = max(maxSum, sum); 

            left++;
            right--;
        }
        return maxSum;
    }
};