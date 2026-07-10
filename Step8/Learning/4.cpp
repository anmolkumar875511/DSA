#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while((n > 0) && ((n & 1) == 0)) {
            n = n >> 1;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    int n = 16; // Example input
    bool result = sol.isPowerOfTwo(n);
    if (result) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }
    return 0;
}