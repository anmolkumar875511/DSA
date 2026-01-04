#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canEat(vector<int>& piles, int k, int h) {
        long long th = 0;
        for(int pile : piles) {
            th = th + (pile + k - 1) / k;
            if(th > h) {
                return false;
            }
        }
        return th <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long sum = 0;
        int high = 0;
        for(int p : piles) {
            sum = sum + p;
            high = max(high, p);
        }

        int low = (sum + h - 1) / h;

        while(low < high) {
            int mid = low + ((high - low) / 2);
            if(canEat(piles, mid, h)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11}; // Example input for piles
    int h = 8; // Example input for hours
    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}