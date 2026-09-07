class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (rowSet.count(c)) return false;
                    rowSet.insert(c);
                }
            }
        }
        
        for (int j = 0; j < 9; j++) {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.') {
                    if (colSet.count(c)) return false;
                    colSet.insert(c);
                }
            }
        }
        
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow*3 + i][boxCol*3 + j];
                        if (c != '.') {
                            if (boxSet.count(c)) return false;
                            boxSet.insert(c);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
