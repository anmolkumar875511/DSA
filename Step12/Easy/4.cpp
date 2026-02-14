#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, n = bills.size();
        for(int bill : bills) {
            if(bill == 5) {
                fives++;
            }
            else if(bill == 10) {
                if(!fives) return false;
                tens++;
                fives--;
            }
            else {
                if(tens && fives) {
                    tens--;
                    fives--;
                }
                else if(fives > 2) fives -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20};
    bool result = sol.lemonadeChange(bills);
    cout << "Can provide change: " << (result ? "Yes" : "No") << endl; // Output: Yes
    return 0;
}