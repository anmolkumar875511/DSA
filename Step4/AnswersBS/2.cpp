#include<iostream>
using namespace std;

class Solution {
public:
  int powerCheck(long long mid, int n, int m) {
    long long ans = 1;
    for(int i = 0; i < n; i++) {
      ans = ans * mid;
      if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
  }
  int NthRoot(int N, int M) {
          if(M < 2) return M;

          int low = 1;
          int high = M;

          while(low <= high) {
            long long mid = low + ((high - low) / 2);
            int status = powerCheck(mid, N, M);

            if(status == 1) return mid;
            else if(status == 0) low = (int)mid + 1;
            else high = (int)mid - 1;
          }
          return -1;
    }
};


int main() {
    Solution sol;
    int N = 3; // Example input for Nth root
    int M = 27; // Example input for M
    int result = sol.NthRoot(N, M);
    cout << N << "th root of " << M << ": " << result << endl;
    return 0;
}