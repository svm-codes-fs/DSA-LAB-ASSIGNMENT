#include <iostream>
using namespace std;
class MaxPQ {
public:
    int arr[100];
    int size;
    MaxPQ() {
        size = 0;
    }
    void insert(int x) {
        arr[size] = x;
        int i = size;
        size++;
        // heapify up
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else break;
        }
    }
    int getMax() {
        if (size == 0) return -1;
        return arr[0];
    }
    int extractMax() {
        if (size == 0) return -1;
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        // heapify down
        int i = 0;
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;
            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
        return maxVal;
    }
};
int main() {
    MaxPQ pq;
    pq.insert(50);
    pq.insert(10);
    pq.insert(40);
    pq.insert(30);
    pq.insert(60);
    cout << "Max: " << pq.getMax() << endl;
    cout << "Extracted: " << pq.extractMax() << endl;
    cout << "Max After Extract: " << pq.getMax() << endl;
    return 0;
}
