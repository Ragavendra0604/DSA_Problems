class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i=0;i<s.length();i++){
            unordered_map<char, int> mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(auto ch : mp){
                    mini = min(mini, ch.second);
                    maxi = max(maxi, ch.second);
                }
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};