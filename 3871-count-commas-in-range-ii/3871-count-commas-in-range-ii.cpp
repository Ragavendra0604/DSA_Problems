class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if (n >= 1000) {
            ans += min(n, 999999LL) - 999;
        }

        if (n >= 1000000) {
            ans += (min(n, 999999999LL) - 999999) * 2;
        }

        if (n >= 1000000000LL) {
            ans += (min(n, 999999999999LL) - 999999999) * 3;
        }

        if (n >= 1000000000000LL) {
            ans += (min(n, 999999999999999LL) - 999999999999LL) * 4;
        }

        if (n >= 1000000000000000LL) {
            ans += (n - 999999999999999LL) * 5;
        }

        return ans;
    }
};
