class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }
        
        vector<pair<char, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result;
        for (auto &p : vec) {
            result.append(p.second, p.first); 
        }

        return result;
    }
};