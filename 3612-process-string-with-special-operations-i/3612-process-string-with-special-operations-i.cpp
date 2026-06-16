class Solution {
public:
    string reverse(string s){
        int n = s.size();
        if(n == 0){
            return "";
        }

        int left = 0;
        int right = n - 1;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
    string processStr(string s) {
        int n = s.size();
        string result = "";

        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result.push_back(s[i]);
            }
            else if(i != 0 && s[i] == '#'){
                result += result;
            }
            else if(s[i] == '%'){
                result = reverse(result);
            }
            else if(s[i] == '*'){
                if(!result.empty()) result.pop_back();
            }
        }

        return result;
    }
};