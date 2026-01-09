#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = m;
        int t = (m + n + 1) >> 1;

        while(low <= high) {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = t - mid1;

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
                if((m + n) & 1) {
                    return max(l1, l2);
                }
                else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
        }
        return 0.0;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0
    return 0;
}