class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        bool flag = true;
        string ans = "";
        int i , j;
        for(i = 0 , j = 0 ; i < n && j < m; ){
            ans += (flag ? word1[i++] : word2[j++]);
            flag = !flag;
        }
        if(i != n){
            ans += word1.substr(i);
        }
        if(j != n){
            ans += word2.substr(j);
        }
        return ans;
    }
};