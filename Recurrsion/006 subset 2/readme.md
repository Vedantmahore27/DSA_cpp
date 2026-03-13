# Subsets II (LeetCode 90)

## Problem Statement

Given an integer array `nums` that **may contain duplicates**, return **all possible unique subsets** (the power set).

The solution set **must not contain duplicate subsets**. Subsets can be returned in **any order**.

---

## Example

### Example 1

```text
Input: nums = [1,2,2]

Output:
[
 [],
 [1],
 [2],
 [1,2],
 [2,2],
 [1,2,2]
]
```

---

# Key Idea

This problem is similar to **Subsets (LeetCode 78)** but with **duplicate elements**.

To avoid duplicate subsets:

1. **Sort the array**
2. **Skip duplicate elements at the same recursion level**

---

# Why Sorting is Important

Sorting groups duplicates together.

Example:

```text
Input:  [2,1,2]
Sorted: [1,2,2]
```

This allows us to easily detect duplicates and skip them.

---

# Duplicate Skipping Trick

Inside the loop we use:

```cpp
if(i > ind && nums[i] == nums[i-1])
    continue;
```

### Meaning

* If the current element is the **same as the previous element**
* And we are at the **same recursion level**
* Then skip it to avoid duplicate subsets.

---

# Approach (Backtracking)

1. Sort the array.
2. Use recursion to generate subsets.
3. Store the current subset at every recursion level.
4. Use a loop to explore further elements.
5. Skip duplicates using the duplicate-check condition.

---

# Algorithm

1. Sort the input array.
2. Start recursion from index `0`.
3. Store the current subset.
4. Iterate through remaining elements.
5. Skip duplicates when necessary.
6. Use **push_back()** and **pop_back()** for backtracking.

---

# C++ Implementation

```cpp
class Solution {
public:

    void solve(int n, int ind,
               vector<int> &nums,
               vector<int> &ans,
               vector<vector<int>> &final){

        final.push_back(ans);

        for(int i = ind; i < n; i++){

            if(i > ind && nums[i] == nums[i-1])
                continue;

            ans.push_back(nums[i]);

            solve(n, i+1, nums, ans, final);

            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;
        vector<vector<int>> final;

        sort(nums.begin(), nums.end());

        solve(n, 0, nums, ans, final);

        return final;
    }
};
```

---

# Recursion Tree Example

For:

```text
nums = [1,2,2]
```

Recursion Tree:

```text
[]
├── [1]
│   ├── [1,2]
│   │   └── [1,2,2]
│
├── [2]
│   └── [2,2]
```

Duplicate branches are skipped.

---

# Time Complexity

Total subsets in worst case:

```text
2^n
```

Copying each subset takes:

```text
O(n)
```

Final complexity:

```text
Time Complexity: O(n * 2^n)
```

---

# Space Complexity

Recursion stack:

```text
O(n)
```

Result storage:

```text
O(n * 2^n)
```

---

# Key Concepts Used

* Recursion
* Backtracking
* Sorting
* Duplicate skipping
* Subset generation

---

# Interview Insight

The **duplicate skipping condition**:

```cpp
if(i > ind && nums[i] == nums[i-1])
```

is commonly used in problems like:

* Subsets II
* Combination Sum II
* Permutations II

Understanding this pattern is essential for mastering **backtracking problems**.

---

# Summary

| Approach        | Time Complexity | Space Complexity |
| --------------- | --------------- | ---------------- |
| Backtracking    | O(n × 2ⁿ)       | O(n × 2ⁿ)        |
| Recursion Stack | —               | O(n)             |

---
