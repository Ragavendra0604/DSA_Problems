class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char,char> opened{{']','['},{'}','{'},{')','('}};
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == opened[ch]){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};