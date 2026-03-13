# Check if There Exists a Subsequence With Given Sum (GFG)

## Problem Statement

Given an array `arr[]` of size `n` and an integer `k`, determine whether there exists a **subsequence** of the array whose **sum equals `k`**.

A subsequence can be formed by **choosing or skipping elements without changing their order**.

Return **true** if such a subsequence exists, otherwise return **false**.

---

## Example

### Example 1

```
Input:
arr = [1, 2, 3]
k = 5

Output:
true
```

**Explanation**

Possible subsequences:

```
[1]
[2]
[3]
[1,2]
[1,3]  ← sum = 4
[2,3]  ← sum = 5 ✅
[1,2,3]
```

Since `[2,3]` gives sum `5`, the answer is **true**.

---

# Approach (Recursion – Pick / Not Pick)

This problem can be solved using the **recursion pick / not-pick technique**.

For every element we have **two choices**:

1. **Pick the element**
2. **Do not pick the element**

We recursively explore both possibilities.

---

## Base Case

When all elements are processed:

```
if(n < 0)
```

If the remaining sum becomes:

```
k == 0
```

then a valid subsequence exists.

---

## Recursive Choices

### Pick the element

We pick the element only if it does not exceed the remaining sum.

```
k >= arr[n]
```

Then reduce the target:

```
k - arr[n]
```

---

### Do not pick the element

Simply move to the next element.

---

# Algorithm

1. Start from the last index.
2. At each index try:

   * pick the element
   * not pick the element
3. If `k` becomes `0`, a valid subsequence exists.
4. Use recursion to explore all possibilities.

---

# C++ Implementation

```cpp
class Solution {
public:

    void solve(int n , vector<int>& arr, int k, bool &ans){

        if(ans) return;

        if(n < 0){
            if(k == 0) ans = true;
            return;
        }

        // pick element
        if(arr[n] <= k)
            solve(n-1, arr, k-arr[n], ans);

        // not pick element
        solve(n-1, arr, k, ans);
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k){

        bool ans = false;

        solve(n-1, arr, k, ans);

        return ans;
    }
};
```

---

# Time Complexity

For each element we have **two choices**:

```
pick
not pick
```

Total recursion calls:

```
2^n
```

**Time Complexity**

```
O(2^n)
```

---

# Space Complexity

Recursion stack depth depends on number of elements:

```
O(n)
```

---

# Key Concepts Used

* Recursion
* Backtracking
* Subsequence generation
* Pick / Not Pick pattern

---

# Interview Insight

This recursive pattern forms the **foundation of many dynamic programming problems**, including:

* Subset Sum
* Partition Equal Subset Sum
* Target Sum
* Count Subsets with Given Sum
* 0/1 Knapsack

The recursive solution can be further optimized using **Dynamic Programming (Memoization or Tabulation)** to reduce complexity from:

```
O(2^n)
```

to

```
O(n × k)
```

---

# Summary

| Approach            | Time Complexity | Space Complexity |
| ------------------- | --------------- | ---------------- |
| Recursion           | O(2^n)          | O(n)             |
| Dynamic Programming | O(n × k)        | O(n × k)         |

---
