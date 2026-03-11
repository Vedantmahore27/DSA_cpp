# Next Greater Element I

## Problem

Given two integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each element in `nums1`, find the **next greater element in `nums2`**.

The **next greater element** of a number `x` in `nums2` is the **first greater number to its right** in `nums2`.
If it does not exist, return `-1`.

---

## Example

```
Input:
nums1 = [4,1,2]
nums2 = [1,3,4,2]

Output:
[-1,3,-1]
```

### Explanation

| Element | Position in nums2 | Next Greater            |
| ------- | ----------------- | ----------------------- |
| 4       | index 2           | No greater element → -1 |
| 1       | index 0           | Next greater is 3       |
| 2       | index 3           | No greater element → -1 |

---

# Intuition

The brute force approach would be:

1. For each element in `nums1`
2. Find its index in `nums2`
3. Scan right side to find a greater element.

This takes **O(n²)** time.

We can optimize this using a **Monotonic Stack**.

---

# Optimized Approach (Monotonic Stack)

Idea:

Traverse `nums2` from **right → left**.

Maintain a **monotonic decreasing stack**.

Steps:

1. If stack is empty → next greater = `-1`
2. If stack top > current element → next greater = stack top
3. Otherwise pop elements until a greater element appears
4. Store result in a **hashmap**
5. Push current element into stack

This creates a mapping:

```
number → next greater element
```

Then simply answer queries for `nums1`.

---

# Algorithm

1. Create a stack
2. Create a hashmap `value → nextGreater`
3. Traverse `nums2` from right to left
4. Maintain a decreasing stack
5. Store results in hashmap
6. Build answer for `nums1` using hashmap

---

# Time Complexity

| Operation             | Complexity |
| --------------------- | ---------- |
| Stack processing      | O(n)       |
| Hashmap lookup        | O(1)       |
| Final result building | O(m)       |

Total:

```
O(n + m)
```

Where
`n = size of nums2`
`m = size of nums1`

---

# Space Complexity

```
O(n)
```
