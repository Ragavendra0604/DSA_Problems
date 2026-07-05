class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left = 0, right = n - 1;
        int leftSum = 0, rightSum = 0;

        int maxSum = 0;

        for(int i = 0 ; i < k ; i++){
            leftSum = leftSum + cardPoints[i];
        }

        maxSum = leftSum;
        for(int i = k - 1 ; i >= 0 ; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[right];
            right--;

            maxSum = max(maxSum, (leftSum + rightSum));
        }
        return maxSum;
    }
};