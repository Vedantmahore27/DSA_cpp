# 🏔️ Find in Mountain Array

## 📌 Problem Statement

You are given access to a **Mountain Array** through an API interface:

```cpp
class MountainArray {
  public:
    int get(int index);
    int length();
};
```

### 🔺 A Mountain Array:

* Strictly increasing → up to a peak
* Strictly decreasing → after the peak

Your task is to find the **index of a target element** in the mountain array.

### ⚠️ Constraints:

* You **cannot access the array directly**
* You must use only:

  * `get(index)`
  * `length()`
* Minimize API calls (important!)

---

## 🧠 Intuition

This problem can be broken into **3 steps**:

### 1️⃣ Find Peak Element

* Use **Binary Search**
* Compare `arr[mid]` and `arr[mid+1]`
* Avoid extra API calls

---

### 2️⃣ Search in Left Half (Ascending)

* Apply standard **Binary Search**

---

### 3️⃣ Search in Right Half (Descending)

* Apply **modified Binary Search**

---

## ⚙️ Approach

### Step 1: Find Peak Index

* If `arr[mid] < arr[mid+1]` → move right
* Else → move left and store peak

---

### Step 2: Binary Search (Ascending Part)

* Search in range `[0 → peak]`

---

### Step 3: Binary Search (Descending Part)

* Search in range `[peak+1 → n-1]`

---

## 💻 Code (C++)

```cpp
class Solution {
public:

    int binarySearchAsc(MountainArray &arr, int start, int end, int target){
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int binarySearchDesc(MountainArray &arr, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;
            else if (val > target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();
        int start = 0, end = n - 1;
        int peak = -1;

        // Step 1: Find Peak
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            } else {
                peak = mid;
                end = mid - 1;
            }
        }

        // Step 2: Search in ascending part
        int res1 = binarySearchAsc(mountainArr, 0, peak, target);
        if (res1 != -1) return res1;

        // Step 3: Search in descending part
        return binarySearchDesc(mountainArr, peak + 1, n - 1, target);
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:**

  * Peak Finding → `O(log n)`
  * Binary Search (2 times) → `O(log n)`
    👉 Overall: `O(log n)`

* **Space Complexity:**

  * `O(1)` (no extra space)

---

## 🔥 Key Observations

* Avoid brute force → too many API calls ❌
* Use **binary search pattern detection** ✔️
* Split problem into **independent parts**

---

## ⚠️ Important Notes

* Always minimize `get()` calls (API constraint)
* Avoid checking both neighbors unnecessarily
* Carefully handle `mid + 1` to prevent overflow

---

## 🧪 Example

### Input (conceptual)

```text
Mountain Array = [1, 3, 5, 7, 6, 4, 2]
target = 6
```

### Output

```text
4
```

---

## 🚀 Key Takeaways

* This is a **combination problem**:

  * Peak Element
  * Binary Search (Ascending + Descending)
* API-based questions test **efficiency, not just correctness**
* Pattern recognition is crucial in Binary Search problems

---

## 📚 Related Problems

* Find Peak Element
* Peak Index in Mountain Array
* Binary Search Variants

---

## ✨ Author

**Vedant Mahore**

* 🎓 G H Raisoni College of Engineering and Management
* 💻 Information Technology | Pre-final Year


🔗 GitHub: https://github.com/Vedantmahore27
🔗 LinkedIn: https://www.linkedin.com/in/vedantmahore27/

---
