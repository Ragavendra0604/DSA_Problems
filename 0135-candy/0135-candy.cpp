class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> left(n, 1);
        int curr = 1, right = 1;
    
        for(int i = 1 ; i < n ; i++){
            if(rating[i-1] < rating[i]){
                left[i] = left[i-1] + 1;
            }
        }

        int minCandy = max(1, left[n - 1]);
        for(int i = n - 2 ; i >= 0 ; i--){
            if(rating[i] > rating[i+1]){
                curr = right + 1;
                right = curr;
            }
            else{
                curr = 1;
                right = curr;
            }
            minCandy += max(left[i], curr);
        }

        return minCandy;
    }
};