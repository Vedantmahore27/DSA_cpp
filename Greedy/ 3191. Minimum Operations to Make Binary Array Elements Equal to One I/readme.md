# 🚀 3191. Minimum Operations to Make Binary Array Elements Equal to One I

## 🧠 Problem Overview

You are given a binary array `nums`.

In one operation, you can flip **three consecutive elements**  
(0 → 1 and 1 → 0).

Your task is to return the **minimum number of operations** required to make all elements equal to `1`.  
If it's impossible, return `-1`.

---

## 💡 Core Insight

We must eliminate every `0`.

Since we can only flip 3 consecutive elements:

👉 Whenever we see a `0`, we must flip starting from that index.  
👉 Delaying the flip will only make it impossible later.

This leads to a **Greedy Strategy**.

---

## 🔥 Greedy Factor

> If the current element is `0`, immediately flip the next three elements.

Why?

- Waiting doesn’t help.
- Earlier flips affect fewer future positions.
- Each decision is locally optimal and safe.

We move from left to right and never backtrack.

---

## 🧩 Algorithm

1. Traverse array from index `0` to `n - 3`.
2. If `nums[i] == 0`:
   - Flip `nums[i]`, `nums[i+1]`, `nums[i+2]`
   - Increment operation count
3. After traversal:
   - If any `0` remains → return `-1`
4. Otherwise → return operation count

---

## ⏱️ Time Complexity

- Single traversal
- Each index flipped at most once

**Time: O(n)**

---

## 📦 Space Complexity

- In-place modification

**Space: O(1)**

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }

        for (int num : nums) {
            if (num == 0) return -1;
        }

        return operations;
    }
};
