class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;
        for(int a=0;a<n;a++){
            for(int b=a+1;b<n;b++){
                unordered_set<long long> hashset;
                for(int c=b+1;c<n;c++){
                    long long sum = (long long)nums[a]+nums[b]+nums[c];
                    long long fourth = (long long)target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[a], nums[b], nums[c], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[c]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};