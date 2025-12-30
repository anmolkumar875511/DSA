#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    long long int merge(vector<int>& nums, vector<int>& temp, long long low, long long mid, long long high) {
        long long int count = 0;
        long long i = low;
        long long j = mid + 1;
        long long k = low;

        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
                count += (mid - i + 1);
            }
        }

        while(i <= mid) {
            temp[k++] = nums[i++];
        }

        while(j <= high) {
            temp[k++] = nums[j++];
        }

        for(long long idx = low; idx <= high; idx++) {
            nums[idx] = temp[idx];
        }

        return count;
    }
	long long int mergeSort(vector<int>& nums, vector<int>& temp, long long low, long long high) {
        long long int count = 0;
        if(low < high) {
            long long mid = low + (high - low) / 2;
            count += mergeSort(nums, temp, low, mid);
            count += mergeSort(nums, temp, mid + 1, high);
            count += merge(nums, temp, low, mid, high);
        }
        return count;   
	}

	long long int numberOfInversions(vector<int> nums) {
	
   		long long count = 0;
		long long n = nums.size();
        vector<int> temp(n);
		return mergeSort(nums, temp, 0, n - 1);

	}
};


int main() {
    Solution sol;
    vector<int> nums = {2, 3, 8, 6, 1}; // Example input
    long long int inversions = sol.numberOfInversions(nums);
    
    cout << "Number of Inversions: " << inversions << endl;
    
    return 0;
}
