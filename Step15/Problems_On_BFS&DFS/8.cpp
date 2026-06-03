#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        vector<int> DIR = {0, -1, 0, 1, 0};
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') {
                q.emplace(0, i);
                visited[0][i] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            if(board[m - 1][i] == 'O') {
                q.emplace(m - 1, i);
                visited[m - 1][i] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                q.emplace(i, 0);
                visited[i][0] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[i][n - 1] == 'O') {
                q.emplace(i, n - 1);
                visited[i][n - 1] = true;
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int j = 0; j < 4; j++) {
                int nx = x + DIR[j], ny = y + DIR[j + 1];
                if(nx < 0 || nx == m || ny < 0 || ny == n || visited[nx][ny] || board[nx][ny] == 'X') continue;
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};


int main() {
    Solution sol;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    sol.solve(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}