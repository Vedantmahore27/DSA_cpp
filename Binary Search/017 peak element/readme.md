# ⛰️ Find Peak Element

## 📌 Problem Statement

A **peak element** is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element and return its index.

* If the array contains multiple peaks, return **any one of them**.
* You may assume:

  * `nums[-1] = -∞`
  * `nums[n] = -∞`

⚡ Your solution must run in **O(log n)** time.

---

## 🧠 Intuition

We can treat the array like a **mountain range ⛰️**:

* If we are moving **uphill** → peak lies on the **right**
* If we are moving **downhill** → peak lies on the **left (or mid)**

Instead of checking both neighbors explicitly, we can use **Binary Search** to find the peak efficiently.

---

## ⚙️ Approach (Binary Search)

1. Initialize:

   * `start = 0`
   * `end = n - 1`

2. While `start < end`:

   * Compute `mid`
   * Compare `nums[mid]` with `nums[mid + 1]`

     * If increasing → move right
     * If decreasing → move left

3. When loop ends → `start == end`, which is the peak index

---

## 📐 Key Observation

* If `nums[mid] < nums[mid + 1]`
  👉 Peak lies on the **right side**

* Else
  👉 Peak lies on the **left side (including mid)**

---

## 💻 Code (C++)

```cpp id="n4z7wr"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Increasing slope → peak on right
                start = mid + 1;
            } else {
                // Decreasing slope → peak on left (including mid)
                end = mid;
            }
        }

        return start;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(log n)` (Binary Search)
* **Space Complexity:** `O(1)` (No extra space used)

---

## 🧪 Example

### Input

```id="k92j2p"
nums = [1,2,3,1]
```

### Output

```id="q8sz6x"
2
```

### Explanation

* `nums[2] = 3` is greater than both neighbors → peak element

---

## 🔄 Another Example

### Input

```id="d9l4s1"
nums = [1,2,1,3,5,6,4]
```

### Output

```id="b1x9pd"
5
```

### Explanation

* `nums[5] = 6` is a peak
* Another valid answer could be index `1` (`2` is also a peak)

---

## 🚀 Key Takeaways

* Binary Search is not just for sorted arrays—it works on **patterns**
* Comparing with `mid + 1` is enough to decide direction
* Avoid unnecessary boundary checks for cleaner code

---

## 📚 Related Topics

* Binary Search
* Arrays
* Divide and Conquer

---

## ✨ Author

**Vedant Mahore**

* 🎓 G H Raisoni College of Engineering and Management
* 💻 Information Technology | Pre-final Year
* 📈 CGPA: 9.67

🔗 GitHub: https://github.com/Vedantmahore27
🔗 LinkedIn: https://www.linkedin.com/in/vedantmahore27/

---
