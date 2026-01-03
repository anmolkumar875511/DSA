#include<iostream>
using namespace std;


class Solution {
public:
    int floorSqrt(int n)  {

        if(n < 2) return n;

        int low = 1;
        int high = n;

        while(low <= high) {
            long long mid = low + ((high - low) / 2);
            long long sq = mid * mid;

            if(sq > n) high = (int)mid - 1;
            else if (sq < n) low = (int)mid + 1;
            else return (int)mid;
        }
        return high;
    }
};

int main() {
    Solution sol;
    int n = 10; // Example input
    int result = sol.floorSqrt(n);
    cout << "Floor of square root of " << n << ": " << result << endl;
    return 0;
}