# 🔍 Search Insert Position

## 📘 Problem Statement

Given a **sorted array of distinct integers** and a target value, return the **index if the target is found**.  

If not, return the **index where it would be inserted** in order.

You must write an algorithm with **O(log n)** runtime complexity.

---

## 🧠 Intuition

Since the array is **sorted**, this problem is a perfect use case for **Binary Search**.

Instead of scanning linearly (which takes O(n)), we can:
- Compare the target with the middle element
- Decide whether to go left or right
- Narrow down the search space efficiently

💡 Key idea:  
Even if the element is **not present**, binary search naturally leads us to the correct **insertion position**.

---

## 🧪 Examples

### Example 1
Input: nums = [1,3,5,6], target = 5
Output: 2

👉 Target exists at index **2**

---

### Example 2
Input: nums = [1,3,5,6], target = 7
👉 Target not present → should be inserted at index **4**
Output: 4


---

## ⚙️ Approach (Binary Search)

1. Initialize two pointers:
   - `low = 0`
   - `high = n - 1`

2. While `low <= high`:
   - Find `mid`
   - If `nums[mid] == target` → return `mid`
   - If `nums[mid] < target` → search right
   - Else → search left

3. If not found:
   - `low` will be the correct insertion position

---

## 💻 Code (C++)

```cpp
class Solution {
public:
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

        return low; // insertion position
    }
};
