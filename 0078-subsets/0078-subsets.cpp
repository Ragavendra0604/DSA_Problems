class Solution {
public:
    void helper(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &result){
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }

        // Pick
        temp.push_back(nums[idx]);
        helper(idx + 1, nums, temp, result);
        
        // Not Pick
        temp.pop_back();
        helper(idx + 1, nums, temp, result);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;

        helper(0, nums, temp, result);
        return result;
    }
};