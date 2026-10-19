class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.size() - 1;
        int start = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                start = mid;
                high = mid - 1;
            }else if(target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(start == -10)return {};
        vector<int> res ;
        while(start < nums.size() && nums[start] == target)res.push_back(start++);
        return res;
        
    }
};