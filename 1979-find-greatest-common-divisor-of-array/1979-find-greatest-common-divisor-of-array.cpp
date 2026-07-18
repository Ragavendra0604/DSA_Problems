class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();

        int min = INT_MAX;
        int max = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i] < min){
                min = nums[i];
            }
        }

        return gcd(min, max);
    }
};