 # 🧠 Partition Equal Subset Sum (LeetCode 416)

## 📌 Problem Statement

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of elements in both subsets is equal, otherwise return `false`.

---

## 💡 Intuition

If the total sum of the array is odd, it is **impossible** to divide it into two equal subsets.

If total sum is even:

- Target = `total_sum / 2`
- The problem reduces to:
  
  👉 Can we find a subset whose sum equals `target`?

This becomes a classic **0/1 Knapsack (Boolean Version)** problem.

---

## 🏗️ Approach (Tabulation - Bottom Up DP)

### 🔹 State Definition


### 🔹 Base Case

- `dp[i][0] = true` → Sum 0 is always possible (by choosing nothing)

### 🔹 Transition

For each element:

- **Not Take** → `dp[i-1][j]`
- **Take** → `dp[i-1][j - nums[i-1]]` (if `nums[i-1] <= j`)
if(nums[i-1] <= j)
dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
else
dp[i][j] = dp[i-1][j];



We check if subset with sum = 11 exists.

---

## 📊 DP Table Representation

| i (elements used) | j=0 | 1 | 2 | 3 | 4 | 5 | ... | 11 |
|-------------------|-----|---|---|---|---|---|-----|----|
| 0 elements        | T   | F | F | F | F | F | ... | F  |
| 1 (1)             | T   | T | F | F | F | F | ... | F  |
| 2 (1,5)           | T   | T | F | F | F | T | ... | F  |
| 3 (1,5,11)        | T   | T | F | F | F | T | ... | T  |

Final answer → `dp[n][target]`

---

# ⚙️ Transition Logic

For each element:
