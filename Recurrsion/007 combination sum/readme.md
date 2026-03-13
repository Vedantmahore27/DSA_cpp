# Combination Sum (LeetCode 39)

## Problem Statement

Given an array of **distinct integers** `candidates` and an integer `target`, return a list of **all unique combinations** of candidates where the chosen numbers sum to `target`.

You may **use the same element multiple times**. The combinations can be returned in **any order**.

---

## Example

### Example 1

```text
Input:
candidates = [2,3,6,7]
target = 7

Output:
[
 [2,2,3],
 [7]
]
```

Explanation:

```text
2 + 2 + 3 = 7
7 = 7
```

---

# Key Idea

This problem is solved using **Backtracking (Pick / Not Pick)**.

For each element we have two choices:

```text
1. Pick the element
2. Do not pick the element
```

Important observation:

```text
When we pick an element, we can pick it again.
```

So the index **does not move forward** after picking.

---

# Backtracking Strategy

At every step:

1. If the target becomes **0**, we found a valid combination.
2. If the target becomes **negative**, stop exploring that path.
3. Try including the current element.
4. Try excluding the current element and move to the next.

---

# Algorithm

1. Start recursion from index `0`.
2. Maintain a temporary list `ds` for the current combination.
3. If `target == 0`, store the combination.
4. If `candidates[i] <= target`, pick the element.
5. Call recursion again **with the same index**.
6. Backtrack using `pop_back()`.
7. Move to the next index for the non-pick case.

---

# C++ Implementation

```cpp
class Solution {
public:

    void solve(int ind,
               vector<int>& candidates,
               int target,
               vector<int>& ds,
               vector<vector<int>>& ans){

        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // pick
        if(candidates[ind] <= target){

            ds.push_back(candidates[ind]);

            solve(ind, candidates, target - candidates[ind], ds, ans);

            ds.pop_back();
        }

        // not pick
        solve(ind + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};
```

---

# Recursion Tree Example

For:

```text
candidates = [2,3]
target = 5
```

Recursion tree:

```text
          []
        /    \
      [2]     []
     /   \
   [2,2]  [2]
   /         \
[2,2,2]     [2,3] ✓
             |
            [3]
```

Valid combination:

```text
[2,3]
```

---

# Time Complexity

The recursion explores multiple possibilities depending on the target.

Worst-case complexity:

```text
O(2^t)
```

Where `t` is proportional to the target.

More commonly written as:

```text
O(2^target)
```

---

# Space Complexity

Recursion stack depth:

```text
O(target)
```

Result storage:

```text
O(k * target)
```

Where `k` is the number of valid combinations.

---

# Key Concepts Used

* Backtracking
* Recursion
* Pick / Not Pick pattern
* Combination generation
* Pruning using `target`

---

# Interview Insight

Difference between **Combination Sum I and II**:

| Problem            | Key Rule                                               |
| ------------------ | ------------------------------------------------------ |
| Combination Sum    | Elements can be reused                                 |
| Combination Sum II | Elements cannot be reused + duplicates must be skipped |

---

# Summary

| Metric           | Complexity          |
| ---------------- | ------------------- |
| Time Complexity  | Exponential         |
| Space Complexity | O(target) recursion |

---
