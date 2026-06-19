#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for(int i = n - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int value;
                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if(nj1 < 0 || nj1 >= m ||
                               nj2 < 0 || nj2 >= m)
                                value += -1e8;
                            else
                                value += front[nj1][nj2];

                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }

            front = curr;
        }

        return front[0][m - 1];
    }
};

int main() {
    Solution s;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.cherryPickup(obstacleGrid) << endl;
    return 0;
}