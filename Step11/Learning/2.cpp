#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] <= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        return heap[0];
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    void buildHeap(vector<int>& arr) {
        heap = arr;

        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void print() {
        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {

    MinHeap h;

    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(2);
    h.insert(8);

    cout << "Heap:\n";
    h.print();

    cout << "Minimum element: " << h.getMin() << endl;

    h.deleteMin();

    cout << "After deleting minimum:\n";
    h.print();

    vector<int> arr = {20, 5, 12, 7, 1};

    MinHeap h2;
    h2.buildHeap(arr);

    cout << "Built heap:\n";
    h2.print();

    return 0;
}