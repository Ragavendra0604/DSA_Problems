class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int result = 0;

        for(int i=1;i<s.length();i++){
            if(s[i] == s[i-1]){
                curr++;
            }
            else{
                result += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        result += min(curr, prev);
        return result;
    }
};