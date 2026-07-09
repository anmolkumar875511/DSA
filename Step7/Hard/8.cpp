#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    void backtrack(int index, string path, long long calc, long long tail, const string& num, int target, vector<string>& ans) {
        if (index == num.size()) {
            if (calc == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            if (i > index && num[index] == '0') {
                break;
            }

            string part = num.substr(index, i - index + 1);
            long long curr = stoll(part);

            if (index == 0) {
                backtrack(i + 1, part, curr, curr, num, target, ans);
            } else {
                backtrack(i + 1, path + "+" + part, calc + curr, curr, num, target, ans);
                backtrack(i + 1, path + "-" + part, calc - curr, -curr, num, target, ans);
                backtrack(i + 1, path + "*" + part, calc - tail + (tail * curr), tail * curr, num, target, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        backtrack(0, "", 0, 0, num, target, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.addOperators("123", 6);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
