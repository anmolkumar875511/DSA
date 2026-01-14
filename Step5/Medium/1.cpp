#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }

        vector<vector<char>> bucket(n + 1);
        for(auto const& [c, freq] : mp) {
            bucket[freq].push_back(c);
        }

        string ans = "";
        for(int i = n; i > 0; i--) {
            for(char c : bucket[i]) {
                ans.append(i, c);
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: "eert" or "eetr"
    return 0;
}