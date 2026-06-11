#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dist = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    sol.floydWarshall(dist);
    for(int i = 0; i < dist.size(); i++) {
        for(int j = 0; j < dist[0].size(); j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}