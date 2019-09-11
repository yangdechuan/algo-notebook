/*
参考： LeetCode 37. Sudoku Solver
 */
#include<vector>

using namespace std;

class Solution {
public:
    // 从(x,y)位置开始深度优先搜索，遇到.时，枚举可以填充的数字，然后判重并加入col、row和squ数组中。
    // 如果成功到达结尾，则返回true，告知搜索可以终止。
    bool dfs(int x, int y, vector<vector<char>>& board, vector<int>& row, vector<int>& col, vector<int>& squ){
        if(y == 9){
            x++;
            y = 0;
        }
        if(x == 9) return true;
        if(board[x][y] == '.'){
            for(int i = 1; i <= 9; i++){
                if(!(
                    row[x] & (1 << i) ||
                    col[y] & (1 << i) ||
                    squ[(x / 3) * 3 + y / 3] & (1 << i)
                    )
                ){
                    row[x] |= (1 << i);
                    col[y] |= (1 << i);
                    squ[(x / 3) * 3 + y / 3] |= (1 << i);
                    board[x][y] = '0' + i;
                    if(dfs(x, y + 1, board, row, col, squ)){
                        return true;
                    }else{
                        board[x][y] = '.';
                        row[x] -= (1 << i);
                        col[y] -= (1 << i);
                        squ[(x / 3) * 3 + y / 3] -= (1 << i);
                    }
                }
            }
            return false;
        }else{
            return dfs(x, y + 1, board, row, col, squ);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        // 分别使用一个整型数组记录每行、每列和每个九宫格内数字的存在情况。
        // 位运算可以极大的简化判断，提高效率。
        vector<int> row(9, 0), col(9, 0), squ(9, 0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    row[i] |= (1 << num);
                    col[j] |= (1 << num);
                    squ[(i / 3) * 3 + j / 3] |= (1 << num);
                }
            }
        }
        dfs(0, 0, board, row, col, squ);
    }
};