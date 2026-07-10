#include<iostream>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        return (n >> k) & 1;
    }
};

int main() {
    Solution sol;
    int n = 5; // Example input
    int k = 2;
    bool result = sol.checkKthBit(n, k);
    if (result) {
        cout << "The " << k << "nd bit of " << n << " is set." << endl;
    } else {
        cout << "The " << k << "nd bit of " << n << " is not set." << endl;
    }
    return 0;
}