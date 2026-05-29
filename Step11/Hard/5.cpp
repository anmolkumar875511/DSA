#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() > min_heap.size()) return max_heap.top();
        else return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}