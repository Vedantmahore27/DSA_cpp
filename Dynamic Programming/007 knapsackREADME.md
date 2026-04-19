# 📦 0/1 Knapsack Problem (Bottom-Up | Tabulation)

## 📌 Problem Statement

Given:

- `val[i]` → value of the ith item  
- `wt[i]` → weight of the ith item  
- `W` → maximum capacity of the knapsack  

Each item can be picked **at most once**.

Your task is to return the **maximum total value** that can be placed in the knapsack without exceeding its capacity.

---

## 🧠 Approach: Bottom-Up Dynamic Programming (Tabulation)

### 🔹 Step 1: Define the State

We define:

Where:

- `i` → number of items considered (0 to n)
- `j` → current capacity (0 to W)

Meaning:

> `dp[i][j]` represents the maximum value achievable using the first `i` items with capacity `j`.

---

### 🔹 Step 2: DP Table Size

Since:

- `i` ranges from `0 → n`
- `j` ranges from `0 → W`

We create a DP table of size:



---

### 🔹 Step 3: Base Cases

1️⃣ No items available:


---

### 🔹 Step 4: Transition Formula

For each item `i` from `1 → n`  
For each capacity `j` from `1 → W`

If weight allows:

