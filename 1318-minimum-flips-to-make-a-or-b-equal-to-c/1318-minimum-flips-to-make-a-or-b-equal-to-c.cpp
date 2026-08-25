class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;

        while(a > 0 || b > 0 || c > 0){
            int aBit = a & 1;
            int bBit = b & 1;
            int cBit = c & 1;

            if(cBit == 0){
                if(aBit == 1){
                    flip++;
                }
                if(bBit == 1){
                    flip++;
                }
            }
            else{
                if(aBit == 0 && bBit == 0){
                    flip++;
                }
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return flip;
    }
};