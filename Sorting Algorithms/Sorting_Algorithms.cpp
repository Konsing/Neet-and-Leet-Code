/*
Run-Time Complexity of Sorting Algorithms

1. Bubble Sort:
   - Best Case: O(n) (when the array is already sorted)
   - Average Case: O(n^2)
   - Worst Case: O(n^2)
   - Space Complexity: O(1) (in-place sorting)

2. Insertion Sort:
   - Best Case: O(n) (when the array is already sorted)
   - Average Case: O(n^2)
   - Worst Case: O(n^2)
   - Space Complexity: O(1) (in-place sorting)

3. Selection Sort:
   - Best Case: O(n^2)
   - Average Case: O(n^2)
   - Worst Case: O(n^2)
   - Space Complexity: O(1) (in-place sorting)

4. Quick Sort:
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n^2) (occurs when the pivot is the smallest or largest element in each partition)
   - Space Complexity: O(log n) (due to recursion stack space)

5. Merge Sort:
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Space Complexity: O(n) (additional space for temporary arrays)
*/

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for (int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i){
        int minIdx = i;
        for (int j = i + 1; j < n; ++j){
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j){
        if (arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2){
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &arr, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    // Bubble Sort
    cout << "Bubble Sort Output: " << endl;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for (int num : arr){
        cout << num << " ";
    }
    cout << endl;

    // Insertion Sort
    cout << "Insertion Sort Output: " << endl;
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr2);
    for (int num : arr2){
        cout << num << " ";
    }
    cout << endl;

    // Selection Sort
    cout << "Selection Sort Output: " << endl;
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr3);
    for (int num : arr3){
        cout << num << " ";
    }
    cout << endl;

    // Quick Sort
    cout << "Quick Sort Output: " << endl;
    vector<int> arr4 = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr4, 0, arr4.size() - 1);
    for (int num : arr4){
        cout << num << " ";
    }
    cout << endl;

    // Merge Sort
    cout << "Merge Sort Output: " << endl;
    vector<int> arr5 = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr5, 0, arr5.size() - 1);
    for (int num : arr5){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
