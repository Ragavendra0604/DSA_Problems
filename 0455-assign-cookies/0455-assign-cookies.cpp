class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int left = 0, right = 0;
        int g_len = g.size(), s_len = s.size();

        while(left < s_len && right < g_len){
            if(s[left] >= g[right]){
                right++;
                left++;
            }
            else{
                left++;
            }
        }

        return right;
    }
};