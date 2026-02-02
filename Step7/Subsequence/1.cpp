#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void insert(vector<string>& v, string s, int n) {
        if(n == 0) {
            v.push_back(s);
            return;
        }
        s.push_back('0');
        insert(v, s, n-1);
        s.pop_back();
        s.push_back('1');
        insert(v, s, n-1);
    }
    vector<string> binstr(int n) {
        string s = "";
        vector<string> v;
        insert(v, s, n);
        return v;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<string> result = sol.binstr(n);
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
