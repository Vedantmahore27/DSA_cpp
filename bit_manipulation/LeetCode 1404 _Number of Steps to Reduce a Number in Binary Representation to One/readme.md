# 🔢 LeetCode 1404  
## Number of Steps to Reduce a Number in Binary Representation to One

### 📌 Problem Link
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

---

## 🧠 Problem Statement

Given a binary string `s`, return the number of steps to reduce it to `"1"` under the following rules:

- If the number is **even**, divide it by 2.
- If the number is **odd**, add 1 to it.

It is guaranteed that you can always reduce the number to one.

---

## 💡 Key Insight

Since the binary string can be up to **500+ bits**, converting it into an integer may cause overflow.

Instead of converting the string to a number, we simulate the operations directly on the binary string.

Even better, we can solve it in **O(n)** time by traversing from right to left while maintaining a carry.

---

## 🚀 Optimal Approach (O(n))

### Idea:

- Traverse from right to left (excluding the first bit).
- Maintain a `carry`.
- If `(bit + carry)` is:
  - **1 (odd)** → requires 2 steps (add 1 + divide by 2)
  - **0 or 2 (even)** → requires 1 step (divide by 2)
- Add carry at the end if needed.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }

        return steps + carry;
    }
};
```

---

## ⏱ Time & Space Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

Where `n` is the length of the binary string.

---

## 🎯 Why This Is Optimal

- Avoids integer overflow.
- Avoids modifying the string repeatedly.
- Single pass solution.
- Interview-optimized approach.

---

## 🏆 Learning Outcome

- Handling large binary numbers
- String-based arithmetic simulation
- Carry handling technique
- Optimization from O(n²) → O(n)

---

### 💻 Author
Vedant Mahore  
3rd Year Engineering Student | Aspiring SDE 🚀
