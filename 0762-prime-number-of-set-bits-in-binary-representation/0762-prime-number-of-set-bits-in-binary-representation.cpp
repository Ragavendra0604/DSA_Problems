class Solution {
public:
    bool isPrime(int n) {
        static unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        return primes.count(n);
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (isPrime(setBits)) {
                count++;
            }
        }
        return count;
    }
};