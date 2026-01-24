class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> st;
        vector<int> NG(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])st.pop();
            if(!st.empty())
                NG[i] = st.top();
            else
                NG[i] = -1;
            st.push(i);
        }
        vector<int> ans(n);
        for(int i = 0 ; i < n ; ++i){
            ans[i] = NG[i] == -1 ? 0 : NG[i] - i;
        }
        return ans;
    }
};