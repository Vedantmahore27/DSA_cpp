# 📌 Lower Bound in Algorithms (Binary Search Concept)

## 📖 Overview

The **Lower Bound** is a fundamental concept used in **binary search** and **sorted data structures**. It helps you efficiently find the position of an element in a sorted array.

---

## 🧠 Definition

The **lower bound** of a value `x` in a sorted array is:

> The **first position (index)** where the element is **greater than or equal to (`>= x`)**.

---

## 📊 Example

```text
Array: [1, 2, 4, 4, 5, 7]

Lower bound of 4 → index 2
Lower bound of 3 → index 2
Lower bound of 6 → index 5
Lower bound of 8 → index 6 (end of array)
```

---

## ⚙️ Implementation

### 🔹 C++ (Using STL)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};

    int x = 4;
    int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    cout << "Lower bound index: " << index << endl;
    return 0;
}
```

---

### 🔹 C++ (Manual Binary Search)

```cpp
int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---

### 🔹 Python

```python
import bisect

arr = [1, 2, 4, 4, 5, 7]
x = 4

index = bisect.bisect_left(arr, x)
print("Lower bound index:", index)
```

---

## ⏱️ Time Complexity

* **O(log n)** → Efficient due to binary search

---

## 🚀 Use Cases

* Searching in sorted arrays
* Finding insertion position
* Competitive programming (very common)
* Range queries (lower_bound + upper_bound)

---

## 🔄 Difference: Lower Bound vs Upper Bound

| Feature   | Lower Bound (`>= x`) | Upper Bound (`> x`) |
| --------- | -------------------- | ------------------- |
| Condition | First ≥ x            | First > x           |
| Use case  | Insert position      | Count occurrences   |

---

## 💡 Pro Tips

* Always use **sorted arrays**
* Combine with **upper_bound** for frequency count:

  ```cpp
  count = upper_bound(arr.begin(), arr.end(), x) 
        - lower_bound(arr.begin(), arr.end(), x);
  ```

---

## 🧪 Practice Problems

* First and Last Occurrence of Element
* Search Insert Position
* Count Occurrences in Sorted Array

---

## 📌 Conclusion

Lower Bound is a **powerful tool** that simplifies searching and positioning in sorted data. Mastering it will significantly improve your efficiency in coding interviews and competitive programming.

---

⭐ *Happy Coding!*
