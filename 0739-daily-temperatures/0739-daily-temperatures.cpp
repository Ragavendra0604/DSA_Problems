class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int st[n]; 
        int tos  = -1;
        vector<int> NG(n);

        for(int i=n-1;i>=0;i--){
            while(tos != -1 && temperatures[i] >= temperatures[st[tos]])--tos;
            if(tos != -1)
                NG[i] = st[tos];
            else
                NG[i] = -1;
            st[++tos] = i;
        }
        vector<int> ans(n);
        for(int i = 0 ; i < n ; ++i){
            ans[i] = NG[i] == -1 ? 0 : NG[i] - i;
        }
        return ans;
    }
};