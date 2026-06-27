class Solution {
public:
    void solve(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            solve(idx, arr, ans, ds, target - arr[idx]);
            ds.pop_back();
        }
        solve(idx + 1, arr, ans, ds, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, candidates, ans, ds, target);

        return ans;
    }
};