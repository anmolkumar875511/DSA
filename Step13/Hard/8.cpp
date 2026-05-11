#include<iostream>
using namespace std;


class Solution {
  public:
    bool isPossible(int a, int b) {
        return (a == 2 || b == 2) && (a + b) != 4;
    }
};


int main() {
    Solution sol;
    int a = 1, b = 2;
    if (sol.isPossible(a, b)) {
        cout << "Possible" << endl;
    } else {
        cout << "Not Possible" << endl;
    }
    return 0;
}