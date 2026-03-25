#define mod 1000000007
#define ll long long int

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();

        ll ans = 0;

        for(int i=0;i<n; ){
            ll count = 0;
            char ch = s[i];

            while(i < n && s[i] == ch){
                count++;
                i++;
            }

            ans += ((count * (count + 1)) / 2) % mod;
        }

        return (int)ans % mod;
    }
};