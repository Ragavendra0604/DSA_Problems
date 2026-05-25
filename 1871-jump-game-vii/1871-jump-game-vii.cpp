class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;

        int windowCount = 0; 

        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0 && reachable[i - minJump]) {
                windowCount++;
            }
            if (i - maxJump - 1 >= 0 && reachable[i - maxJump - 1]) {
                windowCount--;
            }
            reachable[i] = (s[i] == '0' && windowCount > 0);
        }

        return reachable[n - 1];
    }
};