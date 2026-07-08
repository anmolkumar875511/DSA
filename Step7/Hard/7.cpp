#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool f(int i, int j, vector<vector<bool>>& blocks, vector<vector<bool>>& rows, vector<vector<bool>>& columns, vector<vector<char>>& board) {
        if(i == 9) {
            return true;
        }
        if(j == 9) {
            return f(i + 1, 0, blocks, rows, columns, board);
        }
        if(board[i][j] != '.') {
            return f(i, j + 1, blocks, rows, columns, board);
        }

        int idx = (i / 3) * 3 + (j / 3);
        for(int k = 0; k < 9; k++) {
            if(blocks[idx][k] == false && rows[i][k] == false && columns[j][k] == false) {                
                blocks[idx][k] = true;
                rows[i][k] = true;
                columns[j][k] = true;
                board[i][j] = k + '1';

                if(f(i, j + 1, blocks, rows, columns, board)) {
                    return true;
                }

                blocks[idx][k] = false;
                rows[i][k] = false;
                columns[j][k] = false;
                board[i][j] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> blocks (9, vector<bool> (9, false));
        vector<vector<bool>> rows(9, vector<bool> (9, false));
        vector<vector<bool>> columns(9, vector<bool> (9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int idx = (i / 3) * 3 + (j / 3);
                    rows[i][num] = true;
                    columns[j][num] = true;
                    blocks[idx][num] = true;
                }
            }
        }
        f(0, 0, blocks, rows, columns, board);
        return;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    sol.solveSudoku(sudoku);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}