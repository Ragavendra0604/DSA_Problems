class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int sum = 0;
        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            sum = sum + gain[i];
            result.push_back(sum);
        }

        int max = 0;
        for(int i = 0 ; i < n ; i++){
            if(result[i] > max){
                max = result[i];
            }
        }

        return max;
    }
};