#include <bits/stdc++.h>
using namespace std;

void f(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}

int main() {
    int n;
    cin >> n;  // Input the size of the array

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];  // Input array elements in one line

    f(0, arr, n);  // Reverse the array recursively

    for (int i = 0; i < n; i++) cout << arr[i] << " ";  // Output the reversed array
    return 0;
}
