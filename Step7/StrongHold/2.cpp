#include<iostream>
using namespace std;

class Solution {
public:
    double Pow(double x, long n) {
        if(n == 0) {
            return 1.0;
        }
        double half = Pow(x, n/2);
        if(n&1) {
            return half * half * x;
        }
        else {
            return half * half;
        }
    }

    double myPow(double x, int n) {
        bool isNegative = false;
        long N = n;
        if(n < 0) {
            isNegative = true;
            N = -1 * N;
        }

        double res = Pow(x, N);

        if(isNegative) {
            return 1.0 / res;
        }
        else {
            return res;
        }
    }
};


int main() {
    Solution sol;
    double x = 2.0;
    int n = -3;
    cout << sol.myPow(x, n) << endl; // Output: 0.125
    return 0;
}