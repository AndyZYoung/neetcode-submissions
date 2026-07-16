class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));//相比需要动态分配的unordered_set内存开销更小
        vector<vector<bool>> columns(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.')continue;
                int num = c - '0';
                int boxID = (i/3)*3 + (j/3);
                if(rows[i][num] || columns[j][num] || boxes[boxID][num]){//任意一个为true就是找到了相同的数字，返回false
                    return false;
                }
                    rows[i][num] = true;
                    columns[j][num] = true;
                    boxes[boxID][num] = true;
            }
        }
        return true;
    }
};
