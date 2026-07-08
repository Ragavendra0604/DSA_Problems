class Solution {
public:
    int help(vector<int> &nums, int k){
        if (k <= 0) return 0; 
        int n = nums.size();

        int left = 0, right = 0;

        int count = 0;

        unordered_map<int, int> mp;

        while(right < n){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};