# 🍋 LeetCode 860 - Lemonade Change

## 🔗 Problem Link
https://leetcode.com/problems/lemonade-change/

## 📌 Problem Statement

At a lemonade stand, each lemonade costs **$5**.

Customers are standing in a queue and pay with either:
- $5
- $10
- $20

You must provide correct change so that each customer effectively pays $5.

You start with **no change** in hand.

Return `true` if you can provide correct change to every customer, otherwise return `false`.

---

## 🧠 Intuition

This is a **Greedy Problem**.

We process customers one by one and maintain:

- Count of `$5` bills
- Count of `$10` bills

We do NOT need to track `$20` bills because they are never used for change.

### Key Observations:

- If customer pays `$5` → no change needed.
- If customer pays `$10` → must give `$5`.
- If customer pays `$20` → must give `$15`.

For `$20`, we have two options:
1. Give `$10 + $5` (Preferred)
2. Give three `$5` bills

We always prefer option 1 because `$5` bills are more valuable for future transactions.

---

## 🚀 Approach

1. Initialize:
   - `five = 0`
   - `ten = 0`

2. Iterate through each bill:
   - If bill == 5 → `five++`
   - If bill == 10:
     - If no $5 available → return false
     - Else → `five--`, `ten++`
   - If bill == 20:
     - If `ten > 0` AND `five > 0` → give one $10 and one $5
     - Else if `five >= 3` → give three $5
     - Else → return false

3. If loop completes → return true

---
