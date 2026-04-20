# 🔓 Unbounded Knapsack Problem

## 📌 Problem Statement

Given:

* `n` items
* Each item has:

  * Weight: `wt[i]`
  * Value: `val[i]`
* A knapsack with capacity `W`

👉 You can take **unlimited copies** of each item.

### Goal:

Maximize total value such that total weight ≤ `W`.

---

## 🧠 Key Difference from 0/1 Knapsack

| Feature    | 0/1 Knapsack    | Unbounded Knapsack  |
| ---------- | --------------- | ------------------- |
| Item usage | At most once    | Unlimited times     |
| Choice     | Pick / Not Pick | Pick again possible |
| Transition | `i-1`           | `i` stays same      |

---

## 🔁 Recurrence Relation

```
f(i, W) = max(
    val[i] + f(i, W - wt[i]),   // pick (stay on same index)
    f(i-1, W)                   // not pick
)
```

---

## 🧩 Approach 1: Recursion (Brute Force)

### 💡 Idea:

Try all possibilities: pick or not pick.

### ⏱ Complexity:

* Time: Exponential
* Space: O(n)

```cpp
int solve(int i, int W, vector<int>& wt, vector<int>& val) {
    if (i == 0) {
        return (W / wt[0]) * val[0];
    }

    int notTake = solve(i - 1, W, wt, val);

    int take = 0;
    if (wt[i] <= W) {
        take = val[i] + solve(i, W - wt[i], wt, val);
    }

    return max(take, notTake);
}
```

---

## 🧠 Approach 2: Memoization (Top-Down DP)

### 💡 Idea:

Store overlapping subproblems.

### ⏱ Complexity:

* Time: O(n * W)
* Space: O(n * W) + recursion stack

```cpp
int solve(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i == 0) {
        return (W / wt[0]) * val[0];
    }

    if (dp[i][W] != -1) return dp[i][W];

    int notTake = solve(i - 1, W, wt, val, dp);

    int take = 0;
    if (wt[i] <= W) {
        take = val[i] + solve(i, W - wt[i], wt, val, dp);
    }

    return dp[i][W] = max(take, notTake);
}
```

---

## 📊 Approach 3: Tabulation (Bottom-Up DP)

### 💡 Idea:

Build DP table iteratively.

### ⏱ Complexity:

* Time: O(n * W)
* Space: O(n * W)

```cpp
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case
    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[i - 1][w];

            int take = 0;
            if (wt[i] <= w) {
                take = val[i] + dp[i][w - wt[i]];
            }

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}
```

---

## 🚀 Approach 4: Space Optimization (2 Arrays)

### 💡 Idea:

Use only previous + current row.

### ⏱ Complexity:

* Time: O(n * W)
* Space: O(W)

```cpp
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int w = 0; w <= W; w++) {
        prev[w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = prev[w];

            int take = 0;
            if (wt[i] <= w) {
                take = val[i] + curr[w - wt[i]];
            }

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[W];
}
```

---

## ⚡ Approach 5: Single Array Optimization (Best)

### 💡 Insight:

We can use **1D DP** because we reuse the same row.

### ⏱ Complexity:

* Time: O(n * W)
* Space: O(W)

```cpp
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}
```

---

## 🔥 Important Intuition

* **Why `i` stays same when picking?**
  → Because we can reuse the same item unlimited times.

* **Why inner loop runs forward in 1D DP?**
  → To allow reuse of same item in same iteration.

---

## 🧪 Example

```
val = {10, 40, 50, 70}
wt  = {1, 3, 4, 5}
W = 8
```

👉 Output: `110`

---

## 🏁 Summary

* Recursion → brute force
* Memoization → avoids recomputation
* Tabulation → iterative DP
* Space optimized → reduces memory
* 1D DP → most efficient

---

## 💡 When to Use

* Rod Cutting
* Coin Change (Max ways / Min coins variant)
* Resource allocation problems

---

## 🔗 Related Problems

* 0/1 Knapsack
* Rod Cutting
* Coin Change

---

**Made with 💻 for mastering DP**
