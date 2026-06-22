class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char ,int> mp;

        int n = text.size();

        for(char ch : text){
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            {
                mp[ch]++;
            }
        }

        mp['l'] /= 2;
        mp['o'] /= 2;

        int mini = INT_MAX;
        string balloon = "balon";
        for(char ch : balloon){
            mini = min(mini, mp[ch]);
        }

        return mini;
    }
};