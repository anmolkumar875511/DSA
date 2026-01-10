#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int m, int col) {
        int maxE = -1;
        int maxI = -1;
        for (int i = 0; i < m; i++) {
            if (mat[i][col] > maxE) {
                maxE = mat[i][col];
                maxI = i;
            }
        }
        return maxI;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxI = maxElement(mat, m, mid);

            int left = (mid > 0) ? mat[maxI][mid - 1] : -1;
            int right = (mid < n - 1) ? mat[maxI][mid + 1] : -1;

            if (mat[maxI][mid] < left) {
                high = mid - 1;
            }
            else if (mat[maxI][mid] < right) {
                low = mid + 1;
            }
            else {
                return {maxI, mid}; 
            }
        }
        return {-1, -1};
    }
};


int main() {
    vector<vector<int>> mat = {
        {1, 4, 3, 6, 5},
        {16, 41, 23, 22, 6},
        {15, 17, 24, 21, 7},
        {14, 18, 19, 20, 10},
        {13, 12, 11, 8, 9}
    };
    Solution sol;
    vector<int> result = sol.findPeakGrid(mat);
    cout << "Peak element found at: (" << result[0] << ", " << result[1] << ")" << endl; // Output: Peak element found at: (1, 1)
    return 0;
}