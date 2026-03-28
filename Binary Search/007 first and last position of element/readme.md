# 🔍 Find First and Last Position of Element in Sorted Array (LeetCode 34)

---

## 📖 Problem Statement

Given a **sorted array** of integers `nums` and a target value `target`, return the **starting and ending position** of the target.

> If the target is not found, return `[-1, -1]`.

---

## 📊 Examples

```text
Input: nums = [5,7,7,8,8,10], target = 8  
Output: [3,4]
```

```text
Input: nums = [5,7,7,8,8,10], target = 6  
Output: [-1,-1]
```

```text
Input: nums = [], target = 0  
Output: [-1,-1]
```

---

# 🚀 Approaches

---

## 🥉 Approach 1: Brute Force

### 💡 Idea

* Traverse the array
* Track first and last occurrence of target

### 🔹 C++ Code

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            if (first == -1) first = i;
            last = i;
        }
    }
    return {first, last};
}
```

### ⏱️ Complexity

* **Time:** O(n)
* **Space:** O(1)

---

## 🥈 Approach 2: Using Lower Bound & Upper Bound (STL)

### 💡 Idea

* First index → `lower_bound(target)`
* Last index → `upper_bound(target) - 1`

### 🔹 C++ Code

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();

    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (lb < n && nums[lb] == target) {
        return {lb, ub};
    }
    return {-1, -1};
}
```

### ⏱️ Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

## 🥇 Approach 3: Optimal (Single Binary Search Function)

### 💡 Idea

* Use one binary search function
* Modify behavior using a flag:

  * Find first occurrence (move left)
  * Find last occurrence (move right)

---

### 🔹 C++ Code

```cpp
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findFirst)
                    high = mid - 1;
                else
                    low = mid + 1;
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};
```

---

### ⏱️ Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

# 📌 Summary Table

| Approach                | Time Complexity | Space Complexity | Notes               |
| ----------------------- | --------------- | ---------------- | ------------------- |
| Brute Force             | O(n)            | O(1)             | Simple but slow     |
| Lower + Upper Bound     | O(log n)        | O(1)             | Clean & STL-based   |
| ✅ Optimal Binary Search | O(log n)        | O(1)             | Best for interviews |

---

## 🧠 Key Takeaways

* Always use **binary search** on sorted arrays
* Lower bound → first occurrence
* Upper bound → last occurrence
* This pattern is used in many DSA problems

---

⭐ *Master this problem = Strong grip on Binary Search!* 🚀
