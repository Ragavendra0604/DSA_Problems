class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int res = 0;
        vector<int> st = {-1};

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push_back(i);
            }
            else{
                st.pop_back();
                if(st.empty()){
                    st.push_back(i);
                }
                else{
                    res = max(res, i - st.back());
                }
            }
        }

        return res;
    }
};