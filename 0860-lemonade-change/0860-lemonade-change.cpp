class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for(auto bill : bills){
            if(bill == 5){
                mp[bill]++;
            }
            if(bill == 10){
                mp[10]++;
                if(mp[5] > 0) mp[5]--;
                else return false;
            }
            if(bill == 20){
                mp[bill]++;
                if(mp[5] && mp[10]){ 
                    mp[5]--;
                    mp[10]--;
                }
                else if(mp[5] >= 3){
                    mp[5] -= 3;
                }
                else if(mp[10] >= 1 && mp[5] >= 2){
                    mp[10] -= 1;
                    mp[5] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};