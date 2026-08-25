class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        while (n >= d) {
            long long value = d;
            long long multiple = 1;

            while (n >= (value << 1)) {
                value <<= 1;
                multiple <<= 1;
            }

            n -= value;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};