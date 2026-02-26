class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cols = mat[0].size();
        int rows = mat.size();

        int idx = -1;
        int max_Count = -1;
        for(int i=0;i<rows;i++){
            int row_Count = 0;
            for(int j=0;j<cols;j++){
                row_Count += mat[i][j];
            }

            if(row_Count > max_Count){
                max_Count = row_Count;
                idx = i;
            }
        }
        return {idx, max_Count};
    }
};