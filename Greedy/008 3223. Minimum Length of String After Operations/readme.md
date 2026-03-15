# 🚀 3223. Minimum Length of String After Operations

## 🧠 Problem Statement

You are given a string `s`.

You can repeatedly perform the following operation:

- Choose three characters `i < j < k` such that:
  - `s[i] == s[k]`
  - Remove `s[i]` and `s[k]`

Return the minimum possible length of the string after performing operations optimally.

---

## 💡 Key Observation

Each operation removes **2 characters** of the same type.

To remove characters:
- A character must appear **at least 3 times**
- Because we need one in the middle and two equal characters on sides

The final remaining count of each character depends only on its frequency.

---

## 🔥 Core Insight

For each character with frequency `f`:

- If `f` is even → we can reduce it to `2`
- If `f` is odd → we can reduce it to `1`

We can repeatedly remove pairs while keeping at least one character to act as the middle.

So the final contribution of each character is:
