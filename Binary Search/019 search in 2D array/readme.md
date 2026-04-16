# 🔎 Search a 2D Matrix II

## 📌 Problem Statement

You are given an `n x m` matrix with the following properties:

* Integers in each row are sorted in **ascending order**
* Integers in each column are sorted in **ascending order**

Given an integer `target`, return **true** if it exists in the matrix, otherwise return **false**.

---

## 🧠 Intuition

We can take advantage of the sorted nature of the matrix.

👉 Start from the **top-right corner**:

* Moving **left** → values decrease
* Moving **down** → values increase

This allows us to eliminate one row or one column in each step.

---

## ⚙️ Approach (Staircase Search)

1. Start at position `(0, m-1)` → top-right
2. While inside matrix:

   * If current == target → return true
   * If current < target → move **down**
   * If current > target → move **left**
3. If not found → return false

---

## 💻 Code (C++)

```cpp id="2m4f9x"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();      // rows
        int m = matrix[0].size();  // columns

        int i = 0, j = m - 1;

        while (i < n && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }

        return false;
    }
};
```

---

## ⚠️ Important Fix

❌ Your original loop condition:

```cpp id="fix1"
while(i<n && j<m && i>=0 && j>=0)
```

👉 `j < m` is unnecessary and slightly confusing

✅ Correct version:

```cpp id="fix2"
while(i < n && j >= 0)
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n + m)`
* **Space Complexity:** `O(1)`

---

## 🧪 Example

### Input

```text id="ex1"
matrix = [
  [1, 4, 7, 11],
  [2, 5, 8, 12],
  [3, 6, 9, 16]
]
target = 5
```

### Output

```text id="ex2"
true
```

---

## 🚀 Key Takeaways

* Use matrix properties to eliminate rows/columns efficiently
* Top-right (or bottom-left) is the best starting point
* Avoid brute force (`O(n*m)`)

---

## 📚 Related Topics

* Binary Search (2D variant)
* Matrix Traversal
* Two Pointer Technique

---
