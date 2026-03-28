class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string result = "";

        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }

            if(i < 0){
                break;
            }

            int end = i;

            while(i >= 0 && s[i] != ' '){
                i--;
            }

            string word = s.substr(i + 1, end - i);

            if(!result.empty()){
                result += " ";
            }
            result += word;
        }
        return result;
    }
};