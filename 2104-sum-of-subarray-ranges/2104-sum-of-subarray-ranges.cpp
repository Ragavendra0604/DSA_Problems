class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            long long largest = nums[i];
            long long smallest = nums[i];

            for(int j = i + 1 ; j < n ; j++){
                largest = max((int)largest, nums[j]);
                smallest = min((int)smallest, nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum;
    }
};