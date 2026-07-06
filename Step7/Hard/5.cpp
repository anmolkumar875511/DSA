#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> seen(s.length(), false);
        queue.push(0);

        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();

            if (start == s.length()) {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl; // Output: true
    return 0;
}