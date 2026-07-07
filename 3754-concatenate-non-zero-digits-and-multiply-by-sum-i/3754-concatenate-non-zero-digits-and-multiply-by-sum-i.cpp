class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        int m = 1;

        while(n > 0){
            int digit = n % 10;

            if(digit != 0){
                sum += digit;
                x += digit * m;
                m *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};