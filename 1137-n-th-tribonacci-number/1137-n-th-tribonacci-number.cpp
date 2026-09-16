class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) return n;
        else{
            int prev1 = 0;
            int prev2 = 1;
            int prev3 = 1;

            int curr = 0;
            for(int i = 3 ; i <= n ; i++){
                curr = prev1 + prev2 + prev3;
                prev1 = prev2;
                prev2 = prev3;
                prev3 = curr;
            }
            return prev3;
        }
        return 0;
    }
};