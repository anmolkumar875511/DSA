#include<iostream>
#include<vector>
using namespace std;


class Solution1 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        long long n = nums.size();
        long long sn = (n * (n + 1)) / 2;
        long long s2n = (n * (n + 1) * ((2 * n) + 1)) / 6;
        long long s = 0;
        long long s2 = 0;

        for(int num : nums) {
            s = s + num;
            s2 = s2 + ((long long)num * (long long)num);
        }

        long long val1 = s - sn;
        long long val2 = s2 - s2n;
        val2 = val2 / val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};


class Solution2 {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();
        int xr = 0;
        for(int i = 0; i < n; i++) {
            xr = xr ^ nums[i];
            xr = xr ^ (i + 1);
        }

        int num = xr & ~(xr - 1);

        int zero = 0;
        int one = 0;
        
        for(int i = 0; i < n; i++) {
            if((num & nums[i]) != 0) {
                one = one ^ nums[i];
            }
            else {
                zero = zero ^ nums[i];
            }

            if((num & (i + 1)) != 0) {
                one = one ^ (i + 1);
            }
            else {
                zero = zero ^ (i + 1);
            }
        }

        int counter = 0;
        for(int i = 0; i < n; i++) {
            if(zero == nums[i]) {
                counter++;
            }
        }

        if(counter == 2) {
            return {zero, one};
        }
        else {
            return {one, zero};
        }
    }
};



int main() {
    Solution1 sol1;
    Solution2 sol2;
    vector<int> nums = {3,1,3,5,4}; // Example input
    vector<int> result = sol1.findMissingRepeatingNumbers(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    result = sol2.findMissingRepeatingNumbers(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}