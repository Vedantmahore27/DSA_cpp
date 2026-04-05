#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possible(int mid, int k, vector<int> &arr) {
        int students = 1;   // start with first student
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            
            // edge case: single book exceeds mid
            if (arr[i] > mid) return false;

            if (sum + arr[i] <= mid) {
                sum += arr[i];   // assign book
            } else {
                students++;      // new student
                sum = arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        // not enough books
        if (n < k) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, k, arr)) {
                ans = mid;
                high = mid - 1;   // try smaller answer
            } else {
                low = mid + 1;    // increase limit
            }
        }

        return ans;
    }
};
