#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();
            if (word == endWord)
                return level;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (words.count(word)) {
                        q.push({word, level + 1});
                        words.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl; // Output: 5
    return 0;
}