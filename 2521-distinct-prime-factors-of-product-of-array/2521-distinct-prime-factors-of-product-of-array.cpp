class Solution {
public:
    void helper(long long n, unordered_set<int> &primes){
        while(n % 2 == 0){
            primes.insert(2);
            n /= 2;
        }

        for(int i = 3 ; i <= sqrt(n) ; i += 2){
            while( n % i == 0){
                primes.insert(i);
                n /= i;
            }
        }

        if(n > 2){
            primes.insert(n);
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;

        for(int num : nums){
            helper(num, primes);
        }       

        return primes.size();
    }
};