#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 1);
            for(int j = 1; j < i; j++) {
                temp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};


int main() {
    Solution sol;
    int numRows = 5; // Example input
    vector<vector<int>> result = sol.generate(numRows);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}