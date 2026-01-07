#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    bool canAllocate(vector<int>& books, int maxPages, int students) {
        int studentCounter = 1;
        int sumPages = 0;
        for(int pages : books) {
            if(pages > maxPages) {
                return false;
            }
            if(sumPages + pages > maxPages) {
                sumPages = pages;
                studentCounter++;
            }
            else {
                sumPages = sumPages + pages;
            }
        }
        return studentCounter <= students;
    }
    
    int booksAllocation(vector<int> &books, int k) {
    if(k > books.size()) return -1;    
    
    int low = 0;
    int high = 0;
    for(int pages : books) {
        low = max(low, pages);
        high = high + pages;
    }
    int ans = high;
    while(low <= high) {
        int mid = low + ((high - low) / 2);
        
        if(canAllocate(books, mid, k)) {
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
    vector<int> books = {12, 34, 67, 90}; // Example input for books
    int k = 2; // Example input for number of students
    int result = sol.booksAllocation(books, k);
    cout << "Minimum number of pages: " << result << endl;
    return 0;
}