class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        
        int count = 0;
        int maxCounter = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;

            maxCounter = max(maxCounter, count);
        }

        return maxCounter;
    }
};