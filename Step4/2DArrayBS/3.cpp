#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int r = 0;
        int c = col - 1;

        while(r < row && c > -1) {
            if(matrix[r][c] > target) {
                c--;
            }
            else if(matrix[r][c] < target) {
                r++;
            }
            else {
                return true;
            }
        }

        return false;
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 5;
    Solution sol;
    bool result = sol.searchMatrix(matrix, target);
    cout << "Target " << target << (result ? " found." : " not found.") << endl; // Output: Target 5 found.
    return 0;
}