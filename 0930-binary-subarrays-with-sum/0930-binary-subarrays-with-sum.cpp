class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int prefixSum = 0, count = 0;

        mp[prefixSum]++;

        for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i];

            int rm = prefixSum - goal;

            count = count + mp[rm];

            mp[prefixSum]++;
        }
        return count;
    }
};