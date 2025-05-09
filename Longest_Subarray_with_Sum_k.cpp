#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> presummap; // Fixed syntax for the map declaration
    long long sum = 0;
    int maxlen = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        // Case 1: If the entire subarray from the start sums to k
        if (sum == k) {
            maxlen = max(maxlen, i + 1);
        }

        // Case 2: Check if (sum - k) exists in the map
        long long rem = sum - k;
        if (presummap.find(rem) != presummap.end()) {
            int len = i - presummap[rem];
            maxlen = max(maxlen, len);
        }

        // Case 3: Add the current sum to the map if it's not already present
        if (presummap.find(sum) == presummap.end()) {
            presummap[sum] = i;
        }
    }

    return maxlen; // Ensure this is inside the function
}
