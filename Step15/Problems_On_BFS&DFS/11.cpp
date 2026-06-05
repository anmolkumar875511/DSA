#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<functional>
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

class Solution2 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!dict.count(endWord)) return ans;
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int level = dist[word];
            string temp = word;
            for (int i = 0; i < temp.size(); i++) {
                char original = temp[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (!dict.count(temp)) continue;
                    if (!dist.count(temp)) {
                        dist[temp] = level + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    }
                    else if (dist[temp] == level + 1) {
                        parents[temp].push_back(word);
                    }
                }
                temp[i] = original;
            }
        }

        if (!dist.count(endWord)) return ans;
        vector<string> path;
        function<void(string)> dfs = [&](string word) {
            path.push_back(word);

            if (word == beginWord) {
                vector<string> curr(path.rbegin(), path.rend());
                ans.push_back(curr);
            }
            else {
                for (auto &par : parents[word]) {
                    dfs(par);
                }
            }

            path.pop_back();
        };

        dfs(endWord);

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