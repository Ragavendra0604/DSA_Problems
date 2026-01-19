class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0;
        int high = c;

        while(low <= high){
            long long mid = ((long long)low * low) + ((long long)high * high);

            if(mid == c){
                return true;
            }
            else if(mid > c){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
    }
};