class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k % n;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int newIdx;
                if(i % 2 == 0){
                    newIdx = (j + shift) % n;
                }
                else{
                    newIdx = (j - shift + n) % n;
                }
                if(mat[i][j] != mat[i][newIdx]){
                    return false;
                }
            }
        }
        return true;
    }
};