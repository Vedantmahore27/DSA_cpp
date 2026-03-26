# 🔍 Search Insert Position

## 📘 Problem Description

Given a **sorted array of distinct integers** `nums` and a **target value** `target`, return the **index** if the target is found.  

If not, return the **index where it would be inserted** to maintain the sorted order.

You must write an algorithm with **O(log n)** runtime complexity.

---

## 🧾 Examples

### Example 1:
---

## 📌 Constraints

- `1 <= nums.length <= 10^4`  
- `-10^4 <= nums[i] <= 10^4`  
- `nums` contains **distinct values**  
- `nums` is sorted in **ascending order**  
- `-10^4 <= target <= 10^4`  

---

## 🧠 Approach (Binary Search)

Since the array is **sorted**, we can efficiently solve this problem using **Binary Search**.

### 🔹 Key Idea:
- If the target exists → return its index  
- If not → the position where search ends (`low`) is the correct insertion index  

### 🔹 Algorithm:
1. Initialize:
   - `low = 0`
   - `high = n - 1`
2. While `low <= high`:
   - Compute `mid = low + (high - low) / 2`
   - If `nums[mid] == target` → return `mid`
   - If `nums[mid] < target` → search right half (`low = mid + 1`)
   - Else → search left half (`high = mid - 1`)
3. Return `low`

---

## 💻 Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << searchInsert(nums, target);
    return 0;
}
