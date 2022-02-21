class Solution {
public:
    short map_col[9] = {};
    short map_row[9] = {};
    short map_sqr[9] = {};
        
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            int i3 = (i / 3) * 3;
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                short mask = 1 << (board[i][j] -'1');
                if(map_row[i] & mask) return false;
                map_row[i] |= mask;
                if(map_col[j] & mask) return false;
                map_col[j] |= mask;
                if(map_sqr[i3 + (j / 3)] & mask) return false;
                map_sqr[i3 + (j / 3)] |= mask;
            }
        }
        return true;
    }
};