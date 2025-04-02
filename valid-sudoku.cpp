class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
          unordered_set<string> seen;
    
    // Iterate over each cell in the 9x9 board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                // Construct a unique string identifier for the row, column, and sub-box
                char num = board[i][j];
                
                // Check if the number has already been seen in the same row, column, or sub-box
                string rowKey = "row" + to_string(i) + num;
                string colKey = "col" + to_string(j) + num;
                string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + num;
                
                // If any of the keys exist, it means there is a repetition, so return false
                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }
                
                // Otherwise, add the current number to the corresponding sets
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
    }
    
    // If no repetition is found, the board is valid
    return true;
    }
};
