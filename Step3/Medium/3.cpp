#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int element;
        int counter = 0;

        for(int num : nums) {
            if(counter == 0) element = num;
            if(num == element) counter++;
            if(num != element) counter--;
        }
        
        return element;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    
    int result = sol.majorityElement(nums);
    
    cout << "Majority Element: " << result << endl;
    
    return 0;
}