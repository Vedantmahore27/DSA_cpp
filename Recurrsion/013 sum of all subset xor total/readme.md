# Sum of All Subset XOR Totals

## Problem

Given an array `nums`, return the **sum of all XOR totals for every subset of nums**.

The XOR total of an array is defined as the **bitwise XOR of all its elements**, or `0` if the array is empty.

### Example

Input

```
nums = [1,3]
```

Subsets:

```
[]
[1]
[3]
[1,3]
```

XOR values:

```
0
1
3
1 ^ 3 = 2
```

Output

```
0 + 1 + 3 + 2 = 6
```

---

# Approach 1 — Recursion (Generate All Subsets)

## Idea

Generate every subset using recursion and compute the XOR of each subset.

At every element we have two choices:

1. Include the element in the XOR
2. Skip the element

This is the classic **Pick / Not Pick recursion pattern**.

## Code

```cpp
class Solution {
public:

    void solve(int i, vector<int>& nums, int currXor, int &ans){

        if(i == nums.size()){
            ans += currXor;
            return;
        }

        solve(i+1, nums, currXor ^ nums[i], ans);

        solve(i+1, nums, currXor, ans);
    }

    int subsetXORSum(vector<int>& nums) {

        int ans = 0;

        solve(0, nums, 0, ans);

        return ans;
    }
};
```

### Time Complexity

```
O(2^n)
```

Because total subsets are:

```
2^n
```

### Space Complexity

```
O(n)
```

(recursion stack)

---

# Approach 2 — Optimal Bit Manipulation

## Key Observation

Each element appears in **exactly half of the subsets**.

Total subsets:

```
2^n
```

So each element contributes to:

```
2^(n-1) subsets
```

Instead of calculating XOR for every subset individually, we observe:

If we **OR all elements together**, we capture every bit that could appear in XOR.

Let:

```
combined = nums[0] | nums[1] | nums[2] | ... | nums[n-1]
```

Then the total XOR sum becomes:

```
combined * 2^(n-1)
```

---

## Optimal Code

```cpp
class Solution {
public:

    int subsetXORSum(vector<int>& nums) {

        int combined = 0;

        for(int num : nums){
            combined |= num;
        }

        return combined * (1 << (nums.size() - 1));
    }
};
```

---

## Time Complexity

```
O(n)
```

We only traverse the array once.

---

## Space Complexity

```
O(1)
```

No extra memory is used.

---

# Example

```
nums = [1,3]
```

Step 1

```
combined = 1 | 3 = 3
```

Step 2

```
n = 2
2^(n-1) = 2
```

Step 3

```
answer = 3 * 2 = 6
```

Correct result.

---

# Key Concept

The trick is understanding that:

```
Each bit contributes in exactly half of the subsets.
```

So instead of generating subsets, we directly compute the contribution.

---

# Final Complexity Comparison

| Approach          | Time Complexity | Space Complexity |
| ----------------- | --------------- | ---------------- |
| Recursion         | O(2^n)          | O(n)             |
| Optimal Bit Trick | O(n)            | O(1)             |

---

# Conclusion

The optimal approach uses a **bit manipulation insight**:

```
OR of all elements * 2^(n-1)
```

This reduces the problem from **exponential time to linear time**.
