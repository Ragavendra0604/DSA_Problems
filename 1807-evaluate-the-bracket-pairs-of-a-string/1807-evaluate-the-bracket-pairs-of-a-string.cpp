class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;
        for(auto &it : knowledge){
            mp[it[0]] = it[1];
        }

        string key = "";
        string res = "";
        bool flag = false;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                flag = true;
            }
            else if(s[i] == ')'){
                if(mp.find(key) != mp.end()){
                    res += mp[key];
                }
                else{
                    res += "?";
                }

                flag = false;
                key = "";
            }
            else if(flag == true){
                key += s[i];
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};