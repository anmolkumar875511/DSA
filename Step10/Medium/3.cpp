#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int a = -1, b = -1;
        int count_a = 0, count_b = 0, max_len = 0, j = 0;
        for(int i = 0; i < n; i++) {
            if(a == -1) {
                a = nums[i];
                count_a++;
            }
            else if(nums[i] == a) {
                count_a++;
            }
            else if(b == -1) {
                b = nums[i];
                count_b++;
            }
            else if(nums[i] == b) {
                count_b++;
            }
            else {
                while(count_a && count_b) {
                    if(nums[j] == a) {
                        count_a--;
                    }
                    else {
                        count_b--;
                    }
                    j++;
                }
                if(count_a == 0) {
                    a = -1;
                }
                else {
                    b = -1;
                }
                i--;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {0,1,2,1};
    cout << sol.totalFruit(nums) << endl; // Output: 3
    return 0;
}