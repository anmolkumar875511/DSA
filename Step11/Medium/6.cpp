#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c : tasks) freq[c - 'A']++;
        priority_queue<int> max_heap;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) max_heap.push(freq[i]);
        }
        int time = 0;
        while(!max_heap.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            while(cycle-- && !max_heap.empty()) {
                if(max_heap.top() > 1) store.push_back(max_heap.top() - 1);
                max_heap.pop();
                taskCount++;
            }
            for(int &x : store) max_heap.push(x);
            if(max_heap.empty()) time += taskCount;
            else time += n + 1;
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl; // Output: 8
    return 0;
}