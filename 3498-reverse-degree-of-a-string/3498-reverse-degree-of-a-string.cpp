class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;

        int num = 26;
        char ch = 'a';

        int sum = 0;
        while(num >= 0 && ch <= 'z'){
            mp.insert({ch, num});
            num--;
            ch++;
        }

        int i = 1;
        for(auto it : s){
            if(mp.find(it) != mp.end()){
                sum += (mp[it] * i);
                i++;
            }
        }
        return sum;
    }
};