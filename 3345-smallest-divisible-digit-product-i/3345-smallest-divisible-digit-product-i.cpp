class Solution {
public:
    int digitProduct(int num){
        int product = 1;
        while(num > 0){
            int d = num %  10;
            product *= d;
            num /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int prod = digitProduct(n);
            if(prod % t == 0){
                return n;
            }
            n++;
        }
    }
};