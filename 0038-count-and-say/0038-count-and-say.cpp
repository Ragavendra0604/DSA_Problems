class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int k = 1; k < n; k++) {
            string temp = "";
            for (int i = 0; i < result.size(); i++) {
                int count = 1;
                while (i + 1 < result.size() && result[i] == result[i + 1]) {
                    count++;
                    i++;
                }
                temp += to_string(count) + result[i];
            }
            result = temp;
        }
        return result;
    }
};
