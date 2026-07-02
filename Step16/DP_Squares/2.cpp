#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0), curr(n, 0);
        for(int i = 0; i < n; i++) {
            prev[i] = matrix[0][i];
            sum += prev[i];
        }
        for(int i = 1; i < m; i++) {
            curr[0] = matrix[i][0];
            sum += curr[0];
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 1) {
                    curr[j] = min({curr[j - 1], prev[j - 1], prev[j]}) + 1;
                }
                else {
                    curr[j] = 0;;
                }
                sum += curr[j];
            }
            prev = curr;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << sol.countSquares(matrix) << endl;
    return 0;
}