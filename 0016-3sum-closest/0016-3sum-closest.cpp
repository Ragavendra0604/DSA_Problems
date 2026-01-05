class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closetSum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int j = i + 1;
            int k = n - 1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(abs(sum-target) < abs(closetSum - target)){
                    closetSum = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return closetSum;
    }
};