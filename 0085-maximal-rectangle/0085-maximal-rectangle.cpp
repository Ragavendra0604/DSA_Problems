class Solution {
public:
        vector<int> findNSE(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n);

        stack<int> st;
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }
    vector<int> findPSE(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n);

        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int>heights(m, 0);
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }


        return ans;
    }
};