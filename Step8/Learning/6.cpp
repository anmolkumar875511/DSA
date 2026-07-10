#include<iostream>
using namespace std;

class Solution {
public:
    int setBit(int n) {
        n = n | (n + 1);
        return n;
    }
};

int main() {
    Solution sol;
    int n = 6; // Example input for n
    int result = sol.setBit(n);
    cout << "Result: " << result << endl;
    return 0;
}