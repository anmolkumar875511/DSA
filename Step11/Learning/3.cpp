#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; 2 * i + 2 <= n; i++) {
            if(2 * i + 1 < n && arr[i] < arr[2 * i + 1]) return false;
            if(2 * i + 2 < n && arr[i] < arr[2 * i + 2]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << (sol.isMaxHeap(arr) ? "true" : "false") << endl; // Output: true
    return 0;
}