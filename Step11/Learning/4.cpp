#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
private:
    void heapifyDown(vector<int>& heap, int index) {
        int size = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            heapifyDown(heap, largest);
        }
    }

public:
    void buildHeap(vector<int>& heap) {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(heap, i);
        }
    }
};

int main() {
    vector<int> heap = {4, 10, 3, 8, 1};
    MaxHeap maxHeap;
    maxHeap.buildHeap(heap);
    for (int num : heap) {
        cout << num << " ";
    }
    return 0;
}