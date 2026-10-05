class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        stack<int> st;

        for(int i = 0 ; i <= n ; i++){
            int curr = (i == n) ? 0 : heights[i];
            while(!st.empty() && curr < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};