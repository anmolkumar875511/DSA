#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int a = 0;
        int b = 1;
        int fib = 0;
        for(int i = 2; i <= n; i++){
            fib = a + b;
            a = b;
            b = fib;
        }
        return fib;
    }
};

int main() {
    Solution sol;
    int n = 3; // Example input
    int result = sol.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;
    return 0;
}