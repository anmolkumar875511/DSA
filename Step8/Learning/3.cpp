#include<iostream>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        return (n & 1) == 0;
    }
};

int main() {
    Solution sol;
    int n = 4; // Example input
    bool result = sol.isEven(n);
    if (result) {
        cout << n << " is even." << endl;
    } else {
        cout << n << " is odd." << endl;
    }
    return 0;
}