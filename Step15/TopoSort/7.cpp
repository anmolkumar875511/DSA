#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        for(auto &word : words) {
            for(char c : word) {
                indegree[c] = 0;
            }
        }

        int n = words.size();

        for(int i = 0; i < n - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            if(a.size() > b.size() &&
               a.substr(0, b.size()) == b) {
                return "";
            }

            int len = min(a.size(), b.size());
            for(int j = 0; j < len; j++) {
                if(a[j] != b[j]) {
                    if(graph[a[j]].insert(b[j]).second) {
                        indegree[b[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto &[c, deg] : indegree) {
            if(deg == 0) {
                q.push(c);
            }
        }

        string ans;
        while(!q.empty()) {
            char u = q.front();
            q.pop();
            ans.push_back(u);
            for(char v : graph[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans.size() == indegree.size() ? ans : "";
    }
};


int main() {
    Solution sol;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string ans = sol.findOrder(words);
    cout << ans << endl;
    return 0;
}