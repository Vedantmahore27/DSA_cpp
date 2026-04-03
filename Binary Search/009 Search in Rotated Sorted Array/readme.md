# 🔍 Search in Rotated Sorted Array I

## 🧩 Problem Statement
Given a **rotated sorted array** `nums` containing distinct integers and a target value, return the **index of the target** if it exists. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** time complexity.

---

## 📌 Examples

### Example 1
Input: nums = [4,5,6,7,0,1,2], target = 0  
Output: 4  

### Example 2
Input: nums = [4,5,6,7,0,1,2], target = 3  
Output: -1  

### Example 3
Input: nums = [1], target = 0  
Output: -1  

---

## 💡 Intuition

- The array is **sorted but rotated**.
- At least **one half (left or right)** is always sorted.
- Use **Binary Search logic**:
  - Identify which half is sorted.
  - Check if the target lies in that half.
  - Narrow down the search space.

👉 Key Idea:
> Always work on the sorted half of the array.

---

## 🐢 Brute Force Approach

### 🔹 Idea
Traverse the array linearly and check each element.

### 🔹 Code (C++)
```cpp
int search(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) return i;
    }
    return -1;
}


## 💡 Intuition

- Array is **sorted + rotated**
- At least **one half is always sorted**
- Use **Binary Search mindset**
- Trick is to **identify sorted half and eliminate the other**

---

# ⚡ Better Approach (Pivot + Binary Search)

## 🔹 Idea
1. Find the **pivot (smallest element index)**
2. Perform **binary search** in the correct half

## 🔹 Code (C++)
```cpp
int findPivot(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;
        if(nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }
    return low;
}

int binarySearch(vector<int>& nums, int low, int high, int target) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = findPivot(nums);

    if(target >= nums[pivot] && target <= nums[n-1]) {
        return binarySearch(nums, pivot, n-1, target);
    }
    return binarySearch(nums, 0, pivo# 🔍 Search in Rotated Sorted Array I (Optimal Approach)

```

## 📌 Example

### Example 1
Input: nums = [4,5,6,7,0,1,2], target = 0  
Output: 4  

### Example 2
Input: nums = [4,5,6,7,0,1,2], target = 3  
Output: -1  

---

## 💡 Intuition

- The array is **sorted but rotated**
- At any point, **one half is always sorted**
- Use **binary search** to:
  - Identify the sorted half
  - Check if target lies in that half
  - Eliminate the other half

👉 Key Idea:
> Always move towards the half where the target can exist

---
```
## 🚀 Optimal Approach (Modified Binary Search)

### 🔹 Algorithm
1. Initialize `low = 0`, `high = n - 1`
2. Find `mid`
3. If `nums[mid] == target` → return index
4. Check which half is sorted:
   - If `nums[low] <= nums[mid]` → left half sorted  
   - Else → right half sorted  
5. Check if target lies in sorted half:
   - If yes → search there  
   - Else → search in other half  

---
# ⚖️ Better vs Optimal Approach Comparison

| Feature              | Better Approach 🔄 (Pivot + BS)       | Optimal Approach 🚀 (Single BS)     |
|---------------------|--------------------------------------|-------------------------------------|
| Strategy            | Find pivot, then binary search       | Direct modified binary search       |
| Steps               | 2 steps                             | 1 step                              |
| Binary Searches     | 2                                   | 1                                   |
| Time Complexity     | O(log n)                            | O(log n)                            |
| Space Complexity    | O(1)                                | O(1)                                |
| Code Length         | Longer (multiple functions)         | Shorter                             |
| Readability         | Easier to understand                | Slightly tricky                     |
| Logic Complexity    | Low                                 | Medium                              |
| Performance         | Slightly slower (extra step)        | Faster (no pivot needed)            |
| Interview Value     | Good                                | ⭐ Highly preferred                  |

---

## 🎯 When to Use What?

- Use **Better Approach**:
  - When you want **clarity first**
  - Easier to explain if you're stuck

- Use **Optimal Approach**:
  - When aiming for **best solution**
  - Preferred in **interviews**

---

## 🧠 Key Insight

> Better = "Break problem into parts (pivot + search)"  
> Optimal = "Solve everything in one pass using logic"

---

## 🚀 Final Verdict

👉 Always try to reach the **Optimal Approach**  
👉 But explaining **Better → then Optimal** = best interview strategy 💯
## 🔹 Code (C++)

```cpp
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) return mid;

        // Left half is sorted
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if(nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
 }
}

