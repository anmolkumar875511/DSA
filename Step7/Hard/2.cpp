#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, string word, vector<vector<char>>& board, int idx) {
        if(idx == word.size()) {
            return true;
        }
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[idx]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';

        bool found = 
                    dfs(i + 1, j, word, board, idx + 1) ||
                    dfs(i, j + 1, word, board, idx + 1) ||
                    dfs(i - 1, j, word, board, idx + 1) ||
                    dfs(i, j - 1, word, board, idx + 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, word, board, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << (sol.exist(board, word) ? "true" : "false") << endl; // Output: true
    return 0;
}