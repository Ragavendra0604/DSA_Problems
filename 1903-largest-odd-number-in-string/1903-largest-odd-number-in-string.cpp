class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        int idx = -1;

        for(int i=n-1;i>=0;i--){
            int digit = num[i] - '0';

            if(digit % 2 != 0){
                idx = i;
                break;
            }
        }

        int i = 0;
        while(i<n && num[i] == '0'){
            i++;
        }

        return num.substr(i, idx - i + 1);
    }
};