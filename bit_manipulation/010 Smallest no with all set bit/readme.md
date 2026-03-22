# 🧠 Smallest Number With All Set Bits (LeetCode 3370)

## 📌 Problem Statement

You are given a positive integer `n`.

Return the **smallest number `x` such that**:

* `x ≥ n`
* The binary representation of `x` contains **only set bits (all 1s)**

---

## ✨ Examples

### Example 1:

```text
Input: n = 5
Output: 7

Explanation:
7 in binary = 111 (all bits are 1)
```

---

### Example 2:

```text
Input: n = 10
Output: 15

Explanation:
15 in binary = 1111
```

---

### Example 3:

```text
Input: n = 3
Output: 3

Explanation:
3 in binary = 11
```

---

# 🔍 Key Observation

Numbers that have **all bits set (only 1s)** follow this pattern:

| Decimal | Binary |
| ------- | ------ |
| 1       | 1      |
| 3       | 11     |
| 7       | 111    |
| 15      | 1111   |
| 31      | 11111  |

👉 These numbers can be written as:

```text
2^k - 1
```

---

# 💡 Approach

We need to find the **smallest number of the form (2^k - 1)** such that:

```text
2^k - 1 ≥ n
```

---

## 🚀 Strategy

1. Start with `x = 1`
2. Keep doubling (`x = x * 2`) until `x > n`
3. Return `x - 1`

---

## 🧠 Why it works?

* A power of 2 looks like:
  `1000...0` (only one bit set)

* Subtracting 1 gives:
  `111...1` (all bits set)

---

## 🔥 Dry Run

### Example: n = 10

```text
x = 1 → 2 → 4 → 8 → 16 (>10)

Answer = 16 - 1 = 15
```

---

# 💻 Code (C++)

```cpp
class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;

        while (x <= n) {
            x <<= 1;  // multiply by 2
        }

        return x - 1;
    }
};
```

---

# ⏱ Complexity

* Time: `O(log n)`
* Space: `O(1)`

---

# 🧠 Key Concepts

* Bit Manipulation
* Powers of 2
* Pattern Recognition

---

# 🎯 Interview Tip

👉 Best explanation:

> “Numbers with all set bits are of the form (2^k - 1).
> So we find the smallest power of 2 gr
