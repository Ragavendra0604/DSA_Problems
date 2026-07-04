class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }

        unordered_map<int, int> mp;
        int prefixSum = 0, count = 0;
        mp[prefixSum]++;
        for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i];

            int rm = prefixSum - k;

            count = count + mp[rm];

            mp[prefixSum]++;
        }

        return count;
    }
};