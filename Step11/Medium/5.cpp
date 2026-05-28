#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> rank;
        int r = 1;
        for(int x : temp) {
            if(rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }
        
        vector<int> ans;
        for(int x : arr) {
            ans.push_back(rank[x]);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> ans = sol.replaceWithRank(arr, 4);
    for(int num : ans) cout << num << " ";
    return 0;
}