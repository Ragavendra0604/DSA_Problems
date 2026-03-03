class Solution {
public:
    int maxElefind(vector<vector<int>> mat, int row, int col, int mid){
        int maxEle = -1;
        int idx = -1;

        for(int i=0;i<row;i++){
            if(mat[i][mid] > maxEle){
                maxEle = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0, high = cols - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int maxRowIndex = maxElefind(mat, rows, cols, mid);

            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
            int right = mid + 1 < cols ? mat[maxRowIndex][mid + 1] : -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex, mid};
            }
            else if(mat[maxRowIndex][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};