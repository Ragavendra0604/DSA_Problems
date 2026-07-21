class Solution {
public:
    vector<int> findNSE(vector<int> arr, int n){
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }
    vector<int> findPSE(vector<int> arr, int n){
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0 ;  i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> PSE = findPSE(arr, n);
        vector<int> NSE = findNSE(arr, n);

        int total = 0; 
        int mod = (int)(1e9 + 7);
        for(int i = 0 ; i < n ; i++){
            int left = i - PSE[i];
            int right = i - NSE[i];

            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }

        return -total;
    }
};