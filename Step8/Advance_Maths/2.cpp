#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> getDivisors(int n) {
        vector<int> v, u;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                v.push_back(i);
                if(n / i != i) {
                    u.push_back(n / i);
                }
            }
        }
        for(int i = u.size() - 1; i >= 0; i--) {
            v.push_back(u[i]);
        }
        return v;
    }
};


int main() {
    Solution s;
    int n = 12;
    vector<int> ans = s.getDivisors(n);
    for(int num : ans) cout << num << " ";
    return 0;
}