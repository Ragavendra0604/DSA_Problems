class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<int> st;

        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(s[i]);
                int curr_size = st.size();
                max_len = max(max_len, curr_size);
            }
            if(!st.empty() && s[i] == ')'){
                st.pop();
            }
        }

        return max_len;
    }
};