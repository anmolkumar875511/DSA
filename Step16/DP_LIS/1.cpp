#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lis(vector<int>& arr) {
        vector<int> tails;
        for (int num : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout << sol.lis(arr);
    return 0;
}