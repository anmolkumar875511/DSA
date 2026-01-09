#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int i = mid / n;
            int j = mid % n;
            if(matrix[i][j] < target) {
                low = mid + 1;
            }
            else if(matrix[i][j] > target) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int i = mid / n;
            int j = mid % n;
            if(matrix[i][j] < target) {
                low = mid + 1;
            }
            else if(matrix[i][j] > target) {
                high = mid - 1;
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
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);
    cout << "Target " << target << (found ? " found." : " not found.") << endl; // Output: Target 3 found.
    return 0;
}