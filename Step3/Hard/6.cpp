#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int preXOR = 0;
        int counter = 0;

        for(int num : nums) {

            preXOR = preXOR ^ num;

            if(freq.find(preXOR ^ k) != freq.end()) {
                counter = counter + freq[preXOR ^ k];
            }

            freq[preXOR]++;

        }
        
        return counter;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 2, 2, 6, 4}; // Example input
    int k = 6; // Example k
    int result = sol.subarraysWithXorK(nums, k);
    cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;
    return 0;
}