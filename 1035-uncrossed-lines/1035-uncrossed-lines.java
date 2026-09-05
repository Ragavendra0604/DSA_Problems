class Solution {
    private int f(int i, int j , int[] nums1 , int[] nums2 , int[][] dp){
        if(i == nums1.length || j == nums2.length)return 0;
        int x = 0 ;
        if(dp[i][j] != -1)return dp[i][j];
        if(nums1[i] == nums2[j]){
            x = 1 + f(i+1,j+1,nums1,nums2,dp);
        }else{
            x = Math.max(f(i+1,j,nums1,nums2,dp),f(i,j+1,nums1,nums2,dp));
        }
        return dp[i][j] = x;
    }
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length  , n = nums2.length;
        int[][] dp  = new int[m][n];
        for(int i = 0 ;i < m ; ++i){
            Arrays.fill(dp[i],-1);
        }
        return f(0,0,nums1,nums2,dp);
    }
}