#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) {
            return kthElement(nums2, nums1, k);
        }

        int low = max(0, k - n);
        int high = min(m, k);

        while(low <= high) {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = k - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 > 0) {
                l1 = nums1[mid1 - 1];
            }
            if(mid2 > 0) {
                l2 = nums2[mid2 - 1];
            }
            if(mid1 < m) {
                r1 = nums1[mid1];
            }
            if(mid2 < n) {
                r2 = nums2[mid2];
            }

            if(l1 > r2) {
                high = mid1 - 1;
            }
            else if(l2 > r1) {
                low = mid1 + 1;
            }
            else {
                return max(l1, l2);
            }
        }
        return 0.0;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    cout << sol.kthElement(nums1, nums2, k) << endl;
    return 0;
}