#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> DIR = {0, -1, 0, 1, 0};

        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                q.emplace(0, i);
                grid[0][i] = 2;
            }
        }
        for(int i = 0; i < n; i++) {
            if(grid[m - 1][i] == 1) {
                q.emplace(m - 1, i);
                grid[m - 1][i] = 2;
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                q.emplace(i, 0);
                grid[i][0] = 2;
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[i][n - 1] == 1) {
                q.emplace(i, n - 1);
                grid[i][n - 1] = 2;
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + DIR[i], ny = y + DIR[i + 1];
                if(nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == 2 || grid[nx][ny] == 0) continue;
                grid[nx][ny] = 2;
                q.emplace(nx, ny);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) ans++;
                else if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int ans = sol.numEnclaves(grid);
    cout << ans << endl;
    return 0;
}