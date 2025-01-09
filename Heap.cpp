#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Helper function to get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Helper function to get left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Helper function to get right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Heapify down: Ensures the heap property after deletion
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        // Check if left child is smaller than current node
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        // Check if right child is smaller than current smallest
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        // If the smallest is not the current node, swap and continue
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up: Ensures the heap property after insertion
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int key) {
        heap.push_back(key); // Add the new key to the end
        heapifyUp(heap.size() - 1); // Fix the heap property
    }

    // Get the minimum element (root) from the heap
    int getMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    // Remove and return the minimum element from the heap
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        int root = heap[0];

        // Replace the root with the last element and reduce the size
        heap[0] = heap.back();
        heap.pop_back();

        // Fix the heap property
        heapifyDown(0);

        return root;
    }

    // Print the heap as an array
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;

    // Insert elements into the heap
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(7);
    heap.insert(1);

    cout << "Heap elements: ";
    heap.printHeap();

    // Get the minimum element
    cout << "Minimum element: " << heap.getMin() << endl;

    // Extract the minimum element
    cout << "Extracted minimum: " << heap.extractMin() << endl;

    // Print the heap after extraction
    cout << "Heap after extraction: ";
    heap.printHeap();

    return 0;
}
