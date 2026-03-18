# Next Greater Element II

## Problem

Given a **circular integer array `nums`**, return an array `answer` such that:

`answer[i]` is the **next greater element** of `nums[i]`.

The **next greater element** is the first element greater than `nums[i]` when traversing the array to the right.
Since the array is **circular**, after the last element we continue from the beginning.

If no greater element exists, return `-1`.

---

## Example

Input:

```
nums = [1,2,1]
```

Output:

```
[2,-1,2]
```

### Explanation

| Index | Element | Next Greater           |
| ----- | ------- | ---------------------- |
| 0     | 1       | 2                      |
| 1     | 2       | -1                     |
| 2     | 1       | 2 (circular traversal) |

---

# Key Idea

This is similar to **Next Greater Element I**, but the array is **circular**.

Example:

```
nums = [1,2,1]
```

When searching for the next greater element of the last `1`, we wrap around and check the beginning of the array.

To simulate this behavior efficiently, we **iterate the array twice**.

---

# Approach (Monotonic Stack)

We use a **monotonic decreasing stack**.

Steps:

1. Traverse the array **from right to left**
2. Iterate **2 × n times** to simulate circular behavior
3. Maintain a stack that stores potential next greater elements
4. Pop elements from stack while they are **less than or equal to current element**
5. The stack top becomes the **next greater element**
6. Store result only during the **first pass**

---

# Algorithm

1. Let `n = nums.size()`
2. Create result array `ans(n, -1)`
3. Create an empty stack
4. Loop from `2*n - 1` down to `0`
5. Use `i % n` to simulate circular index
6. Maintain monotonic decreasing stack
7. Store next greater element

---

# Time Complexity

| Operation        | Complexity |
| ---------------- | ---------- |
| Stack operations | O(n)       |
| Array traversal  | O(2n)      |

Total:

```
O(n)
```

Each element is pushed and popped at most once.

---

# Space Complexity

```
O(n)
```

Used for stack and result array.

---


---

# Dry Run Example

```
nums = [1,2,1]
```

Processing twice:

```
Index: 5 4 3 2 1 0
Value: 1 2 1 1 2 1
```

Final result:

```
[2,-1,2]
```

---

# Important Concepts

* Circular array handling
* Monotonic stack pattern
* Efficient stack usage
* Modulo indexing (`i % n`)

---

# Difference from Next Greater Element I

| Feature    | NGE I     | NGE II      |
| ---------- | --------- | ----------- |
| Array Type | Normal    | Circular    |
| Lookup     | HashMap   | Index based |
| Traversal  | 1 pass    | 2 passes    |
| Stack      | Monotonic | Monotonic   |

---

# Related Problems

* Next Greater Element I
* Daily Temperatures
* Stock Span Problem
* Largest Rectangle in Histogram

All of these use the **monotonic stack pattern**.

---

# Tags

```
Stack
Monotonic Stack
Circular Array
Array
```

---

# Author

Vedant Mahore
DSA Practice – Interview Preparation
