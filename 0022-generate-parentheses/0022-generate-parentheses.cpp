class Solution {
public:
    void solve(int open, int close, string ds, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(ds);
            return;
        }

        if(open > 0) solve(open - 1, close, ds + "(", ans);

        if(close > open) solve(open, close - 1, ds + ")", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, "", ans);
        return ans;
    }
};