// https://leetcode.com/problems/count-mentions-per-user/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineTime(numberOfUsers, -61);  // initially online

        // --- Sort events: primary by timestamp, secondary OFFLINE before MESSAGE ---
        sort(events.begin(), events.end(), [&](const auto& a, const auto& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 != t2) return t1 < t2;

            // same timestamp: OFFLINE first
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });

        // --- Process events ---
        for (auto& e : events) {
            string type = e[0];
            int timestamp = stoi(e[1]);

            if (type == "OFFLINE") {
                int id = stoi(e[2]);
                offlineTime[id] = timestamp;
                continue;
            }

            // MESSAGE event
            string msg = e[2];

            if (msg == "ALL") {
                // ALL → mentions every user
                for (int i = 0; i < numberOfUsers; i++) {
                    mentions[i]++;
                }
            } 
            else if (msg == "HERE") {
                // HERE → mentions only online users
                for (int i = 0; i < numberOfUsers; i++) {
                    if (timestamp - offlineTime[i] > 59) {
                        mentions[i]++;
                    }
                }
            } 
            else {
                // id<number> tokens
                int id = 0;
                for (int i = 0; i <= (int)msg.size(); i++) {
                    if (i < msg.size() && isdigit(msg[i])) {
                        id = id * 10 + (msg[i] - '0');
                    }
                    else if (i == msg.size() || msg[i] == ' ') {
                        mentions[id]++;
                        id = 0;
                    }
                }
            }
        }

        return mentions;
    }
};

int main() {
    Solution sol;
    int numberOfUsers = 3;
    vector<vector<string>> events = {
        {"MESSAGE", "1", "ALL"},
        {"OFFLINE", "2", "1"},
        {"MESSAGE", "61", "HERE"},
        {"MESSAGE", "62", "id2 id0"}
    };
    vector<int> result = sol.countMentions(numberOfUsers, events);
    cout << "Mentions per user: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}