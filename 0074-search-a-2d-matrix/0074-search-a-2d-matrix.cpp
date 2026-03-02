class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int low = 0, high = (cols * rows) - 1;
        while(low <= high){
            int mid = (low + (high - low) / 2);
            int ele_col = mid / cols;
            int ele_row = mid % cols;

            if(matrix[ele_col][ele_row] == target){
                return true;
            }

            else if(matrix[ele_col][ele_row] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};