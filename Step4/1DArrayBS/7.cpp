#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findBound(const vector<int>& arr, int target, bool isFirst) {

        int low = 0;
        int high = arr.size() - 1;
        int bound = -1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(arr[mid] > target) {
                high = mid - 1;
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                bound = mid;
                if(isFirst) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return bound;
    }

    int countOccurrences(const vector<int>& arr, int target) {

        int first = findBound(arr, target, true);

        if(first == -1) {
            return 0;
        }

        int last = findBound(arr, target, false);

        return last - first + 1;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1,2,2,2,3,4,5}; // Example input
    int target = 2; // Example target
    int count = sol.countOccurrences(arr, target);
    cout << "Count of " << target << ": " << count << endl;
    return 0;
}