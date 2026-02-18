#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<pair<int, int>> job;
    int maxDeadline = 0;

    for(int i = 0; i < n; i++) {
        job.emplace_back(profit[i], deadline[i]);
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    sort(job.begin(), job.end(), greater<pair<int, int>>());

    vector<int> schedule(maxDeadline + 1, -1);
    int count = 0, totalProfit = 0;

    for(int i = 0; i < n; i++) {
        int currProfit = job[i].first;
        int currDeadline = job[i].second;

        for(int j = currDeadline; j > 0; j--) {
            if(schedule[j] == -1) {
                schedule[j] = i;
                count++;
                totalProfit += currProfit;
                break;
            }
        }
    }
    return {count, totalProfit};
}


int main() {
    vector<int> deadline = {2, 1, 2, 1};
    vector<int> profit = {100, 19, 27, 25};

    vector<int> result = jobSequencing(deadline, profit);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;

    return 0;
}