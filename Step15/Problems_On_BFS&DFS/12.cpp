#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        const vector<int> DIR = {0, -1, 0, 1, 0};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != '1') continue;
                q.emplace(i, j);
                grid[i][j]++;
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = x + DIR[k], ny = y + DIR[k + 1];
                        if(nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] != '1') continue;
                        q.emplace(nx, ny);
                        grid[nx][ny]++;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    int ans = sol.numIslands(grid);
    cout << ans << endl;
    return 0;
}