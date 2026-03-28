# 📌 Upper Bound in Algorithms (Binary Search Concept)

## 📖 Overview

The **Upper Bound** is a key concept used in **binary search** on sorted arrays. It helps determine the position where a value would go such that all elements before it are less than or equal.

---

## 🧠 Definition

The **upper bound** of a value `x` in a sorted array is:

> The **first position (index)** where the element is **strictly greater than (`> x`)**.

---

## 📊 Example

```text id="k8d2hf"
Array: [1, 2, 4, 4, 5, 7]

Upper bound of 4 → index 4
Upper bound of 3 → index 2
Upper bound of 7 → index 6 (end of array)
Upper bound of 0 → index 0
```

---

## ⚙️ Implementation

### 🔹 C++ (Using STL)

```cpp id="u8a1g2"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};

    int x = 4;
    int index = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

    cout << "Upper bound index: " << index << endl;
    return 0;
}
```

---

### 🔹 C++ (Manual Binary Search)

```cpp id="b3s9x1"
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
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

```python id="z4m7q2"
import bisect

arr = [1, 2, 4, 4, 5, 7]
x = 4

index = bisect.bisect_right(arr, x)
print("Upper bound index:", index)
```

---

## ⏱️ Time Complexity

* **O(log n)** → Efficient due to binary search

---

## 🚀 Use Cases

* Finding the **first element greater than x**
* Counting occurrences of an element
* Determining insertion position (right side)
* Range queries in sorted arrays

---

## 🔄 Difference: Lower Bound vs Upper Bound

| Feature   | Lower Bound (`>= x`) | Upper Bound (`> x`) |
| --------- | -------------------- | ------------------- |
| Condition | First ≥ x            | First > x           |
| Use case  | Insert position      | Range end / count   |

---

## 💡 Pro Tips

* Works only on **sorted arrays**
* To count occurrences of `x`:

  ```cpp
  count = upper_bound(arr.begin(), arr.end(), x) 
        - lower_bound(arr.begin(), arr.end(), x);
  ```
* Helps in solving many **binary search variations**

---

## 🧪 Practice Problems

* Count occurrences in sorted array
* First and last position of element
* Search insert position
* Find range of a target value

---

## 📌 Conclusion

Upper Bound is an essential concept for efficiently handling sorted data. It complements **Lower Bound** and is widely used in coding interviews and competitive programming.

---

⭐ *Keep Practicing, Keep Growing!*
