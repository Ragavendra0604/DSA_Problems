public class Solution {
    public bool Check(int[] nums) {
        int n = nums.Length;

        int count = 0;        
        if(nums[n-1] > nums[0]){
            count++;
        }
        
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[i-1]){
                count++;
            }
        }

        if(count <= 1){
            return true;
        }
        return false;
    }
}