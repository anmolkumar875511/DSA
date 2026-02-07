#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void helper(string digits, unordered_map<char, string>& map, vector<string>& v, int i, string s) {
        if(i == digits.size()) {
            v.push_back(s);
            return;
        }
        for(int j = 0; j < 3; j++) {
            s.push_back(map[digits[i]][j]);
            helper(digits, map, v, i+1, s);
            s.pop_back();
        }
        if(digits[i] == '7' || digits[i] == '9') {
            s.push_back(map[digits[i]][3]);
            helper(digits, map, v, i+1, s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> v;
        helper(digits, map, v, 0, "");
        return v;
    }
};


int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);
    
    cout << "Letter combinations: ";
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    
    return 0;
}
