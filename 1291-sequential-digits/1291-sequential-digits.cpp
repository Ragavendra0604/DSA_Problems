class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        list<int> l;

        for(int i = 1 ; i <= 9 ; i++){
            int temp = i * 10;
            for(int j = i + 1 ; j <= 9 ; j++){
                temp += j;
                l.push_back(temp);
                temp = temp * 10;
            }
        }

        vector<int> result;
        for(auto it : l){
            if(it >= low && it <= high){
                result.push_back(it);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};