class Solution {
public:
    void helper(int i, int j, string s, vector<string> &ans){
        if(i == 0 && j == 0) {
            ans.push_back(s);
            return;
        }
        if(i > 0) helper(i - 1, j, s + "(", ans);

        if(j > i) helper(i, j - 1, s + ")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        helper(n, n, "", ans);

        return ans;
    }
};