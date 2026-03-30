# 🔍 Search in Rotated Sorted Array II

## 🧩 Problem Statement
Given a **rotated sorted array** `nums` that may contain **duplicates**, and a target value, return **true** if the target exists in the array, otherwise return **false**.

---

## 📌 Examples

### Example 1
Input: nums = [2,5,6,0,0,1,2], target = 0  
Output: true  

### Example 2
Input: nums = [2,5,6,0,0,1,2], target = 3  
Output: false  

### Example 3
Input: nums = [1,1,1,1,1], target = 1  
Output: true  
# 🔍 Search in Rotated Sorted Array II (With Duplicates)

## 🧩 Problem Statement
Given a **rotated sorted array** `nums` that may contain **duplicates**, and a target value, return **true** if the target exists in the array, otherwise return **false**.

---

## 📌 Examples

### Example 1
Input: nums = [2,5,6,0,0,1,2], target = 0  
Output: true  

### Example 2
Input: nums = [2,5,6,0,0,1,2], target = 3  
Output: false  

---

## 💡 Intuition

- Array is **sorted + rotated**
- Duplicates make it **hard to detect sorted half**
- We gradually improve:
  - Brute → Linear Search  
  - Better → Pivot + Binary Search  
  - Optimal → Modified Binary Search  

---

# 🐢 Brute Force Approach

## 🔹 Idea
Traverse the entire array and check each element.

## 🔹 Code (C++)
```cpp
bool search(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) return true;
    }
    return false;
}
---


## 💡 Intuition

- The array is **sorted but rotated**
- Unlike previous version, **duplicates are allowed**
- Because of duplicates:
  - Sometimes we **cannot determine which half is sorted**
- So we:
  1. Try normal binary search logic
  2. If stuck due to duplicates → **shrink search space**

👉 Key Idea:
> When confused due to duplicates, move both pointers inward

---
int findPivot(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(nums[mid] > nums[high]) low = mid + 1;
        else if(nums[mid] < nums[high]) high = mid;
        else high--; // handle duplicates
    }
    return low;
}

bool binarySearch(vector<int>& nums, int low, int high, int target) {
    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target) return true;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = findPivot(nums);

    if(target >= nums[pivot] && target <= nums[n-1])
        return binarySearch(nums, pivot, n-1, target);

    return binarySearch(nums, 0, pivot-1, target);
}



## 🚀 Optimal Approach (Modified Binary Search)

### 🔹 Algorithm

1. Initialize `start = 0`, `end = n - 1`
2. Find `mid`
3. If `nums[mid] == target` → return true
4. If duplicates:
   - `nums[start] == nums[mid] == nums[end]`
   - → `start++`, `end--`
5. Else determine sorted half:
   - Left sorted → `nums[start] <= nums[mid]`
   - Right sorted → otherwise
6. Check if target lies in sorted half:
   - Yes → move inside
   - No → move to other half

---

## 🔹 Code (C++)

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target) return true;

            // Handle duplicates
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }

            // Left half sorted
            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half sorted
            else {
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};
