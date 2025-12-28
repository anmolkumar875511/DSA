#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        int counter = 1, maxCounter = 1;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int n : s){
            if(s.find(n - 1) == s.end()) {

                counter = 1;

                while(s.find(n + counter) != s.end()) {
                    counter++;
                }

                maxCounter = max(maxCounter, counter);
            }
        }
        return maxCounter;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(nums);

    cout << "Length of the longest consecutive elements sequence: " << result << endl;

    return 0;
}