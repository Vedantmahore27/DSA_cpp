# Subsets (LeetCode 78)

## Problem Statement

Given an integer array `nums` of unique elements, return **all possible subsets** (the power set).

The solution set **must not contain duplicate subsets**. The subsets can be returned in **any order**.

---

## Example

### Example 1

```
Input: nums = [1,2,3]

Output:
[
 [],
 [1],
 [2],
 [3],
 [1,2],
 [1,3],
 [2,3],
 [1,2,3]
]
```

---

# Approach (Recursion – Pick / Not Pick)

This problem can be solved using the **Pick / Not Pick recursion technique**.

For each element in the array, we have **two choices**:

1. **Pick the element** and include it in the current subset.
2. **Do not pick the element** and move to the next element.

By recursively exploring both choices, we generate **all possible subsets**.

---

# Recursion Flow

At each index `i`:

```
1. Add nums[i] to the subset
2. Move to next index
3. Remove nums[i] (backtrack)
4. Explore the path where the element is not included
```

Example for `nums = [1,2]`

```
        []
       /  \
     [1]   []
    /  \   /  \
 [1,2] [1] [2] []
```

Generated subsets:

```
[]
[1]
[2]
[1,2]
```

---

# Algorithm

1. Start from index `0`.
2. If the index reaches `n`, store the current subset.
3. Include the current element and recurse.
4. Remove the element (backtrack).
5. Recurse without including the element.
6. Store all generated subsets.

---

# C++ Implementation

```cpp
class Solution {
public:

    void solve(int n, int i, vector<int> &nums,
               vector<int> ans,
               vector<vector<int>> &final){

        if(i == n){
            final.push_back(ans);
            return;
        }

        // pick
        ans.push_back(nums[i]);
        solve(n, i+1, nums, ans, final);

        ans.pop_back();

        // not pick
        solve(n, i+1, nums, ans, final);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> final;
        vector<int> ans;

        solve(n, 0, nums, ans, final);

        return final;
    }
};
```

---

# Time Complexity

Each element has **two choices**:

```
pick
not pick
```

Total number of subsets:

```
2^n
```

Copying each subset takes `O(n)`.

```
Time Complexity: O(n × 2^n)
```

---

# Space Complexity

Recursion stack depth:

```
O(n)
```

Result storage:

```
O(n × 2^n)
```

---

# Key Concepts Used

* Recursion
* Backtracking
* Subsequence generation
* Pick / Not Pick pattern
* Power Set generation

---

# Interview Insight

This recursion pattern is used in many important problems:

* Subsets
* Subsequence Sum
* Combination Sum
* Partition Problems
* Knapsack
* Target Sum

Understanding this pattern helps solve **many recursion and dynamic programming problems efficiently**.

---

# Summary

| Approach                  | Time Complexity | Space Complexity |
| ------------------------- | --------------- | ---------------- |
| Recursion (Pick/Not Pick) | O(n × 2^n)      | O(n × 2^n)       |
| Recursion Stack           | —               | O(n)             |

---
