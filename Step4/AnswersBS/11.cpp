#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    bool canAllocate(vector<int>& arr, int maxArea, int painter) {
        int sumArea = 0;
        int countPainter = 1;
        for(int num : arr) {
            if(sumArea + num > maxArea) {
                countPainter++;
                sumArea = num;
                
                if(countPainter > painter) {
                    return false;
                }
            }
            else {
                sumArea = sumArea + num;
            }
        }
        return true;
    }
    
    int painterPartition(vector<int>& arr, int k) {
        int low = 0;
        int high = 0;
        
        for(int num : arr) {
            low = max(low, num);
            high = high + num;
        }
        int ans = high;
        
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(canAllocate(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {10, 20, 30, 40}; // Example input for board lengths
    int k = 2; // Example input for number of painters
    int result = sol.painterPartition(arr, k);
    cout << "Minimum time to paint all boards: " << result << endl;
    return 0;
}