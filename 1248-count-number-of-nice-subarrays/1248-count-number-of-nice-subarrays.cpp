class Solution {
public:
    int atMost(vector<int> &nums, int k){
        int n = nums.size();
        if(k < 0) return 0;

        int left = 0;
        int right = 0;

        int count = 0, sum = 0;
        while(right < n){
            sum += nums[right];
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }

        return count;
    }
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

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};