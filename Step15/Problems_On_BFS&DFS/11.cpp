#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(), wordList.end());
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()) {
            vector<string> a = q.front();
            q.pop();
            if(a.size() > level) {
                level++;
                for(string it : used) word.erase(it);
                used.clear();
            }
            string s = a.back();
            if(s == endWord) {
                if(ans.size() == 0) ans.push_back(a);
                else if(ans[0].size() == a.size()) ans.push_back(a);
            }
            for(int i = 0; i < s.size(); i++) {
                char original = s[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if(word.count(s)) {
                        used.push_back(s);
                        a.push_back(s);
                        q.emplace(a);
                        a.pop_back();
                    }
                }
                s[i] = original;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}