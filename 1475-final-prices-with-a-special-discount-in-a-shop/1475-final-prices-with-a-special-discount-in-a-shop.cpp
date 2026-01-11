class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size(); 
        for (int i = 0; i < n; i++) { 
            while (!st.empty() && prices[st.top()] >= prices[i]) { 
                int idx = st.top(); 
                st.pop(); 
                prices[idx] -= prices[i]; 
            } 
            st.push(i); 
        } 
        return prices;
    }
};