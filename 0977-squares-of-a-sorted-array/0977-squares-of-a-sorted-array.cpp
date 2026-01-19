class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        
        int i = 0;
        int j = n - 1;
        int idx = n - 1;

        while(i <= j) {
            if(abs(nums[i]) > abs(nums[j])){
                result[idx] = nums[i] * nums[i];
                i++;
            }
            else{
                result[idx] = nums[j] * nums[j];
                j--;
            }
            idx--;
        }
        return result;
    }
};