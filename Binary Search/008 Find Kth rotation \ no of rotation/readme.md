# 🔄 Find K Rotation (Minimum Element in Rotated Sorted Array)

---

## 📖 Problem Statement

Given a **sorted array that has been rotated** `k` times, find the value of `k`.

> The rotation count is equal to the **index of the minimum element**.

---

## 📊 Examples

```text
Input: arr = [4,5,6,7,1,2,3]
Output: 4
Explanation: Minimum element (1) is at index 4
```

```text
Input: arr = [1,2,3,4,5]
Output: 0
```

```text
Input: arr = [3,4,5,1,2]
Output: 3
```

---

# 🚀 Approaches

---

## 🐢 Approach 1: Brute Force (Linear Scan)

### 💡 Idea

Traverse the array and find the **minimum element index**.

### 🔹 C++ Code

```cpp
int findKRotation(vector<int> &arr) {
    int minVal = INT_MAX, index = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            index = i;
        }
    }
    return index;
}
```

### ⏱️ Complexity

* **Time:** O(n)
* **Space:** O(1)

---

## ⚡ Approach 2: Binary Search (Neighbor Check)

### 💡 Idea

Minimum element is **smaller than both neighbors**

### 🔹 C++ Code

```cpp
int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    if (arr[start] <= arr[end]) return 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] < arr[next] && arr[mid] < arr[prev])
            return mid;

        else if (arr[mid] >= arr[0])
            start = mid + 1;

        else
            end = mid - 1;
    }
    return 0;
}
```

### ⏱️ Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

## 🔥 Approach 3: Optimized Binary Search (Compare with End)

### 💡 Idea

* If `arr[mid] > arr[end]` → go right
* Else → go left (including mid)

### 🔹 C++ Code

```cpp
int findKRotation(vector<int> &arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[end])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}
```

### ⏱️ Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

## 🚀 Approach 4: Binary Search (Compare Low, Mid, High)

### 💡 Idea

At any point:

* If **left part is sorted** → minimum lies in right half
* Else → minimum lies in left half (including mid)

👉 Use comparison between `low`, `mid`, and `high`

---

### 🔹 C++ Code

```cpp
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If left half is sorted
        if (arr[low] <= arr[mid]) {
            // Minimum must be in right half
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        // Left half is not sorted → pivot lies here
        else {
            high = mid;
        }
    }

    return low;
}
```

---

### 🧠 Intuition

* One half is always **sorted**
* Minimum element lies in the **unsorted half**
* Use `low`, `mid`, `high` comparison to decide direction

---

### ⏱️ Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

# 🧠 Key Insights

* Rotation count = **index of minimum element**
* Binary search helps eliminate half every time
* Focus on finding the **unsorted region**

---

# 📌 Summary Table

| Approach             | Time     | Space | Notes            |
| -------------------- | -------- | ----- | ---------------- |
| Brute Force          | O(n)     | O(1)  | Simple           |
| Neighbor Check       | O(log n) | O(1)  | Classic          |
| Compare with End     | O(log n) | O(1)  | Clean & popular  |
| Compare Low-Mid-High | O(log n) | O(1)  | Strong intuition |

---

# ⚠️ Edge Cases

* Already sorted → return 0
* Single element → return 0
* No duplicates assumed

---

# ⭐ Conclusion

This problem is all about identifying the **pivot (minimum element)** using binary search.

👉 Once you understand:

* Sorted half vs unsorted half
* Boundary detection

You can solve many advanced problems easily 🚀

---
