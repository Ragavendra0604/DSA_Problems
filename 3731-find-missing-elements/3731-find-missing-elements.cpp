class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int minVal = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < minVal){
                minVal = nums[i];
            }
        }

        int maxVal = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
            }
        }
    
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> missing;
    
        for (int i = minVal; i <= maxVal; i++) {
            if (numSet.find(i) == numSet.end()) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};