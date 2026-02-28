# 2864. Maximum Odd Binary Number

## 🧠 Problem Statement

You are given a binary string `s`.

Return the maximum odd binary number that can be formed by rearranging the bits of `s`.

A binary number is **odd** if its last bit is `'1'`.

---

## 💡 Intuition

To make a binary number:

- **Maximum** → Place as many `'1'`s as possible at the left (higher place value).
- **Odd** → The last bit must be `'1'`.

So the strategy is:

1. Count total number of `'1'`.
2. Keep exactly **one `'1'`** for the last position (to make it odd).
3. Place remaining `'1'`s at the beginning.
4. Fill the remaining positions with `'0'`.

---

## 🚀 Greedy Approach

### 🔥 Greedy Factor:
> Place all `'1'`s at the left to maximize value, and reserve one `'1'` at the end to ensure the number remains odd.

We:
- Do not try all permutations.
- Do not use backtracking.
- Make the locally optimal placement directly.

This guarantees the maximum possible odd number.

---

## 🧩 Algorithm

1. Count total `'1'` in string.
2. Reserve one `'1'` for the last position.
3. Fill first `(ones - 1)` positions with `'1'`.
4. Fill middle positions with `'0'`.
5. Place `'1'` at last index.

---

## ⏱️ Time Complexity

- Counting ones → `O(n)`
- Constructing result → `O(n)`
- **Overall: O(n)**

---

## 📦 Space Complexity

- `O(1)` if modifying in place
- `O(n)` if constructing new string

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        string result(ones - 1, '1');
        result += string(s.size() - ones, '0');
        result += '1';
        
        return result;
    }
};
