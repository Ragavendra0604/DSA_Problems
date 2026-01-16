class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;

        int minEle = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                minEle = min(minEle, nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                minEle = min(minEle, nums[low]);
                low = mid + 1;
            }
            else{
                minEle = min(minEle, nums[mid]);
                high = mid - 1;
            }
        }
        return minEle;
    }
};