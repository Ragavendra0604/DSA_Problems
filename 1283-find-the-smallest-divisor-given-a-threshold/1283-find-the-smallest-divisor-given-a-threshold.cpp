class Solution {
public:
    int findDivisor(vector<int>& nums, int num){
        int n = nums.size();

        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i] / (double)num);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }

        int low = 1;
        int high = max;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int smallDiv = findDivisor(nums, mid);
            
            if(smallDiv <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};