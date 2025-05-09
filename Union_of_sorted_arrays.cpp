#include<bits/stdc++.h>
vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size(); // Length of the first array
    int n2 = b.size(); // Length of the second array

    int i = 0; // Pointer for traversing the first array `a`
    int j = 0; // Pointer for traversing the second array `b`

    vector<int> unionArr; // Resultant array to store the union of `a` and `b`

    // Merging and removing duplicates while both arrays are not fully traversed
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) { 
            // If the current element in `a` is smaller or equal to the current element in `b`
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]); // Add `a[i]` to unionArr if it's not a duplicate
            }
            i++; // Move to the next element in `a`
        } else { 
            // If the current element in `b` is smaller than the current element in `a`
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]); // Add `b[j]` to unionArr if it's not a duplicate
            }
            j++; // Move to the next element in `b`
        }
    }

    // Adding remaining elements from `b` (if any)
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]); // Add `b[j]` to unionArr if it's not a duplicate
        }
        j++;
    }

    // Adding remaining elements from `a` (if any)
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]); // Add `a[i]` to unionArr if it's not a duplicate
        }
        i++;
    }

    return unionArr; // Return the final union array
}
