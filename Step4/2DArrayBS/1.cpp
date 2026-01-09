#include<iostream>
#include<vector>
using namespace std;


// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(!(m)) {
            return -1;
        }
        int maxI = -1;
        int j = n - 1;
        
        for(int i = 0; i < m; i++) {
            while(j > -1 && matrix[i][j] == 1) {
                j--;
                maxI = i;
            }
        }
        return maxI;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    Solution sol;
    int result = sol.rowWithMax1s(matrix);
    cout << "Row with maximum 1s: " << result << endl; // Output: Row with maximum 1s: 2
    return 0;
}