#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    // Merge two sorted halves [low, mid] and [mid+1, high]
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Add remaining elements from the left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Add remaining elements from the right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int>& arr, int low, int high) {
    if (low == high) return;  // Base case: a single element is already sorted
    int mid = (low + high) / 2;

    // Recursively sort the two halves
    mS(arr, low, mid);
    mS(arr, mid + 1, high);

    // Merge the sorted halves
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr, int n) {
    mS(arr, 0, n - 1);
}
