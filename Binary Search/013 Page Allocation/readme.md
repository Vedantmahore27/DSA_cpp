# 📚 Allocate Minimum Number of Pages

## 🧩 Problem Statement

Given an array `arr[]` where each element represents the number of pages in a book, and an integer `k` representing the number of students, allocate books to students such that:

* Each student gets **at least one book**
* Books are allocated in **contiguous order**
* The goal is to **minimize the maximum number of pages assigned to a student**

---

## 🚫 Constraints

* `1 ≤ N ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^4`
* `1 ≤ k ≤ N`

---

## 💡 Example

### Input:

```
arr = [12, 34, 67, 90]
k = 2
```

### Output:

```
113
```

### Explanation:

Possible allocations:

* [12, 34] and [67, 90] → max = 157 ❌
* [12, 34, 67] and [90] → max = 113 ✅
* [12] and [34, 67, 90] → max = 191 ❌

👉 Minimum possible maximum = **113**

---

## 🚀 Approach

### 🔹 Binary Search on Answer

We search for the minimum possible value of maximum pages.

#### Search Space:

```
low  = max(arr)
high = sum(arr)
```

---

### 🔹 Feasibility Check (`possible` function)

We check if it's possible to allocate books such that:

* No student gets more than `mid` pages
* Total students used ≤ `k`

---

### 🔹 Algorithm Steps

1. Initialize:

   * `low = max(arr)`
   * `high = sum(arr)`

2. Apply Binary Search:

   * Compute `mid`
   * Check if allocation is possible

     * If YES → store answer, try smaller (`high = mid - 1`)
     * If NO → increase (`low = mid + 1`)

---

## 🧠 Intuition

* Treat `mid` as the **maximum pages a student can handle**
* Try to distribute books greedily
* If more than `k` students are required → `mid` is too small

---

## 💻 Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possible(int mid, int k, vector<int> &arr) {
        int students = 1;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return false;

            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                students++;
                sum = arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (n < k) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, k, arr)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## ⏱️ Time Complexity

* Binary Search: `O(log(sum - max))`
* Feasibility Check: `O(N)`
* **Overall:** `O(N log N)`

---

## 📌 Key Points

* Books must be **allocated in order**
* Each student must get **at least one book**
* Use **Binary Search on Answer**
* Greedy strategy inside feasibility check

---

## 🔁 Similar Problems

* Painter’s Partition Problem
* Split Array Largest Sum
* Allocate Minimum Distance

---

## 🏆 Summary

> Divide the books into `k` contiguous groups such that the **maximum pages assigned to any student is minimized**.

---

✨ Happy Coding!
