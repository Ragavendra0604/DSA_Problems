class Solution {
public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;

        for (int num : nums) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            minVal = min(minVal, digitSum);
        }

        return minVal;
    }
};
