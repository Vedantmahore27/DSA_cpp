# 🧠 LeetCode 168 - Excel Sheet Column Title

## 🔗 Problem Link
https://leetcode.com/problems/excel-sheet-column-title/

## 📌 Problem Statement

Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

For example:

- 1 -> "A"
- 2 -> "B"
- 26 -> "Z"
- 27 -> "AA"
- 28 -> "AB"

---

## 💡 Intuition

This problem is similar to converting a number into a **base-26 system**, but with a twist:

- There is **no zero**
- Instead of digits `0-25`, we use letters `A-Z`
- `A = 1`, `B = 2`, ..., `Z = 26`

Because of this, we need to:
- Subtract 1 before taking modulo
- Build the string in reverse order
- Reverse it at the end

---

## 🚀 Approach

1. While `columnNumber > 0`
2. Decrement `columnNumber` by 1
3. Find remainder: `columnNumber % 26`
4. Convert remainder to character: `'A' + remainder`
5. Append to result
6. Divide `columnNumber` by 26
7. Reverse final string

---
