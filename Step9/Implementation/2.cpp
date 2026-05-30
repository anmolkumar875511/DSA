#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class StockSpanner {
private:
    vector<int> store;
    stack<int> st;
    int n = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        store.push_back(price);
        n++;
        while(!st.empty() && store[st.top() - 1] <= store[n - 1]) st.pop();
        int ans = n;
        if(!st.empty()) {
            ans = ans - st.top();
        }

        st.push(n);
        return ans;
    }
};


int main() {
    StockSpanner obj;
    cout << obj.next(100) << endl;
    cout << obj.next(80) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(70) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(75) << endl;
    cout << obj.next(85) << endl;
    return 0;
}