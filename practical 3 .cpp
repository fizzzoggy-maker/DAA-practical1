#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// ---------- MAX HEAP ----------

void createMaxHeap(vector<int>& data, int size, int index)
{
    int parent = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && data[leftChild] > data[parent])
        parent = leftChild;

    if (rightChild < size && data[rightChild] > data[parent])
        parent = rightChild;

    if (parent != index)
    {
        swap(data[index], data[parent]);
        createMaxHeap(data, size, parent);
    }
}

void heapSortMax(vector<int>& data)
{
    int size = data.size();

    // Constructing Max Heap
    for (int i = size / 2 - 1; i >= 0; --i)
        createMaxHeap(data, size, i);

    // Sorting using Max Heap
    for (int last = size - 1; last >= 1; --last)
    {
        swap(data[0], data[last]);
        createMaxHeap(data, last, 0);
    }
}

// ---------- MIN HEAP ----------

void createMinHeap(vector<int>& data, int size, int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && data[leftChild] < data[smallest])
        smallest = leftChild;

    if (rightChild < size && data[rightChild] < data[smallest])
        smallest = rightChild;

    if (smallest != index)
    {
        swap(data[index], data[smallest]);
        createMinHeap(data, size, smallest);
    }
}

void heapSortMin(vector<int>& data)
{
    int size = data.size();

    // Constructing Min Heap
    for (int i = size / 2 - 1; i >= 0; --i)
        createMinHeap(data, size, i);

    // Sorting using Min Heap
    for (int last = size - 1; last >= 1; --last)
    {
        swap(data[0], data[last]);
        createMinHeap(data, last, 0);
    }

    // Min Heap gives descending order, so reverse it
    reverse(data.begin(), data.end());
}

// ---------- MAIN FUNCTION ----------

int main()
{
    int number;

    cout << "Enter total number of elements: ";
    cin >> number;

    vector<int> values(number);

    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate random values
    for (int i = 0; i < number; ++i)
    {
        values[i] = rand() % 100000;
    }

    vector<int> maxData(values);
    vector<int> minData(values);

    // ===== MAX HEAP SORT TIME =====

    auto maxStart = high_resolution_clock::now();

    heapSortMax(maxData);

    auto maxFinish = high_resolution_clock::now();

    // ===== MIN HEAP SORT TIME =====

    auto minStart = high_resolution_clock::now();

    heapSortMin(minData);

    auto minFinish = high_resolution_clock::now();

    // Calculate execution time
    auto maxNano =
        duration_cast<nanoseconds>(maxFinish - maxStart);

    auto maxMicro =
        duration_cast<microseconds>(maxFinish - maxStart);

    auto maxMilli =
        duration_cast<milliseconds>(maxFinish - maxStart);

    auto minNano =
        duration_cast<nanoseconds>(minFinish - minStart);

    auto minMicro =
        duration_cast<microseconds>(minFinish - minStart);

    auto minMilli =
        duration_cast<milliseconds>(minFinish - minStart);

    // ===== DISPLAY RESULT =====

    cout << "\n====================================";
    cout << "\n        MAX HEAP SORT";
    cout << "\n====================================\n";

    cout << "Execution Time:\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";
    cout << "Milliseconds : " << maxMilli.count() << " ms\n";

    cout << "\n====================================";
    cout << "\n        MIN HEAP SORT";
    cout << "\n====================================\n";

    cout << "Execution Time:\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";
    cout << "Milliseconds : " << minMilli.count() << " ms\n";

    return 0;
}
