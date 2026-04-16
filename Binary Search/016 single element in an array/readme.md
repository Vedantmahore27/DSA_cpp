# 🔍 Single Element in a Sorted Array

## 📌 Problem Statement

Given a **sorted array** of integers where every element appears **exactly twice**, except for one element that appears only once, find that single element.

Your solution must run in **O(log n)** time and **O(1)** space.

---

## 🧠 Intuition

Since the array is sorted and elements appear in pairs:

* Before the single element → pairs follow pattern:

  ```
  (even index, odd index)
  ```
* After the single element → pattern breaks:

  ```
  (odd index, even index)
  ```

We use **Binary Search** to efficiently locate where this pattern breaks.

---

## ⚙️ Approach (Binary Search with Index Parity)

1. Handle **edge cases**:

   * If only one element → return it
   * If first/last element is unique → return it

2. Apply **Binary Search**:

   * Find `mid`
   * Check if `nums[mid]` is the single element
   * Otherwise:

     * If pairing is correct → move right
     * If pairing is broken → move left

---

## 📐 Key Observations

| Index Type | Expected Pair |
| ---------- | ------------- |
| Even       | `mid + 1`     |
| Odd        | `mid - 1`     |

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();

        // Edge cases
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Check if mid is the single element
            if (mid > 0 && mid < n-1 &&
                nums[mid] != nums[mid-1] &&
                nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // Check pairing condition
            if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid-1])) {
                // Correct pairing → move right
                start = mid + 1;
            } else {
                // Broken pairing → move left
                end = mid - 1;
            }
        }

        return -1;
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

```
nums = [1,1,2,3,3,4,4,8,8]
```

### Output

```
2
```

---

## 🚀 Key Takeaways

* Binary Search can be applied beyond simple searching.
* Index parity (even/odd) helps identify patterns in paired arrays.
* Always handle **edge cases** before applying binary logic.

---

## 📚 Related Topics

* Binary Search
* Arrays
* Bit Manipulation (alternative approach)

---

## ✨ Author

**Vedant Mahore**

* 🎓 G H Raisoni College of Engineering and Management
* 💻 IT | Pre-final Year
* 📈 CGPA: 9.67

🔗 [GitHub](https://github.com/Vedantmahore27)
🔗 [LinkedIn](https://www.linkedin.com/in/vedantmahore27/)

---
