#include<bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> &a, int n) {
    int largest = a[0];       // Initialize the largest value as the first element.
    int slargest = -1;        // Initialize second largest as -1 (or an invalid value).
    for (int i = 1; i < n; i++) { // Loop through the array starting from the second element.
        if (a[i] > largest) {     // If the current element is greater than the largest:
            slargest = largest;  // Update second largest to the previous largest.
            largest = a[i];      // Update largest to the current element.
        } else if (a[i] < largest && a[i] > slargest) { 
            // If the current element is between the largest and second largest:
            slargest = a[i];     // Update second largest to the current element.
        }
    }
    return slargest;  // Return the second largest value.
}

int secondsmallest(vector<int> &a, int n) {
    int smallest = a[0];       // Initialize the smallest value as the first element.
    int ssmallest = INT_MAX;   // Initialize second smallest as the maximum possible integer.
    for (int i = 1; i < n; i++) { // Loop through the array starting from the second element.
        if (a[i] < smallest) {     // If the current element is smaller than the smallest:
            ssmallest = smallest;  // Update second smallest to the previous smallest.
            smallest = a[i];       // Update smallest to the current element.
        } else if (a[i] > smallest && a[i] < ssmallest) { 
            // If the current element is between the smallest and second smallest:
            ssmallest = a[i];      // Update second smallest to the current element.
        }
    }
    return ssmallest;  // Return the second smallest value.
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = secondlargest(a, n);   // Call `secondlargest` to find the second largest.
    int ssmallest = secondsmallest(a, n); // Call `secondsmallest` to find the second smallest.
    return {slargest, ssmallest};         // Return both as a vector.
}
