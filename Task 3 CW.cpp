#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono> 
#include <algorithm> 

using namespace std;
using namespace std::chrono;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int bubble_sort_count(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

int selection_sort_count(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minimum]) {
                minimum = j;
            }
        }
        swap(arr[i], arr[minimum]);
    }
    return comparisons;
}

int insertion_sort_count(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparisons++;
        arr[j + 1] = key;
    }
    return comparisons;
}

int heapify(int arr[], int size, int index) {
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    int comparisons = 0;

    if (left < size) {
        comparisons++;
        if (arr[left] < arr[smallest]) {
            smallest = left;
        }
    }

    if (right < size) {
        comparisons++;
        if (arr[right] < arr[smallest]) {
            smallest = right;
        }
    }

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        comparisons += heapify(arr, size, smallest);
    }
    return comparisons;
}

int heap_sort_count(int arr[], int size) {
    int comparisons = 0;

    for (int i = (size / 2) - 1; i >= 0; i--) {
        comparisons += heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        comparisons += heapify(arr, i, 0);
    }

    return comparisons;
}

void generate_array(int arr[], int size, int type) {
    for (int i = 0; i < size; i++) {
        if (type == 0) {
            arr[i] = rand() % 100;
        }
        else if (type == 1) {
            arr[i] = i;
        }
        else {
            arr[i] = size - i;
        }
    }
}

void test_comparisons() {
    srand(time(0));

    ofstream results("sorting_results.csv");
    results << "Size,Heap Comparisons,Heap Time (ms),Bubble Comparisons,Bubble Time (ms),"
        "Selection Comparisons,Selection Time (ms),Insertion Comparisons,Insertion Time (ms)\n";

    int arr[30];


    for (int size = 1; size <= 30; size++) {
        for (int type = 0; type < 3; type++) {

            generate_array(arr, size, type);


            int temp[30];
            copy(arr, arr + size, temp);


            auto start = high_resolution_clock::now();
            int heap_comp = heap_sort_count(temp, size);
            auto end = high_resolution_clock::now();
            auto heap_time = duration_cast<milliseconds>(end - start).count();

            copy(arr, arr + size, temp);
            start = high_resolution_clock::now();
            int bubble_comp = bubble_sort_count(temp, size);
            end = high_resolution_clock::now();
            auto bubble_time = duration_cast<milliseconds>(end - start).count();

            copy(arr, arr + size, temp);
            start = high_resolution_clock::now();
            int selection_comp = selection_sort_count(temp, size);
            end = high_resolution_clock::now();
            auto selection_time = duration_cast<milliseconds>(end - start).count();

            copy(arr, arr + size, temp);
            start = high_resolution_clock::now();
            int insertion_comp = insertion_sort_count(temp, size);
            end = high_resolution_clock::now();
            auto insertion_time = duration_cast<milliseconds>(end - start).count();


            results << size << "," << heap_comp << "," << heap_time << ","
                << bubble_comp << "," << bubble_time << ","
                << selection_comp << "," << selection_time << ","
                << insertion_comp << "," << insertion_time << "\n";
        }
    }

    results.close();
    cout << "Results saved to sorting_results.csv" << endl;
}

int main() {
    test_comparisons();
    return 0;
}
