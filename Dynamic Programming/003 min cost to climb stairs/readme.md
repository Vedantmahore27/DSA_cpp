# Min Cost Climbing Stairs Problem (C++)

## 📌 Problem Statement

You are given an array `cost[]` where `cost[i]` is the cost of stepping
on the i-th stair.

You can: - Start from index 0 or 1 - Move either 1 step or 2 steps at a
time

Return the **minimum cost** to reach the top.

------------------------------------------------------------------------

## 🔢 Example

Input:\
`cost = [10, 15, 20]`

Output:\
`15`

Explanation:\
Start at index 1 → pay 15 → reach top

------------------------------------------------------------------------

# 🚀 C++ Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

Try both choices (1 step or 2 steps) and take minimum.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& cost) {
    if (i >= cost.size()) return 0;

    return cost[i] + min(solve(i + 1, cost), solve(i + 2, cost));
}

int minCostClimbingStairs(vector<int>& cost) {
    return min(solve(0, cost), solve(1, cost));
}
```

### ⏱ Complexity

-   Time: **O(2\^n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 2️⃣ Memoization (Top-Down DP)

### 💡 Idea

Store results to avoid recomputation.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& cost, vector<int>& dp) {
    if (i >= cost.size()) return 0;

    if (dp[i] != -1) return dp[i];

    return dp[i] = cost[i] + min(solve(i + 1, cost, dp), solve(i + 2, cost, dp));
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, -1);

    return min(solve(0, cost, dp), solve(1, cost, dp));
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 3️⃣ Tabulation (Bottom-Up DP)

### 💡 Idea

Build solution from bottom.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1],
                    dp[i - 2] + cost[i - 2]);
    }

    return dp[n];
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 4️⃣ Space Optimized

### 💡 Idea

Only last two states needed.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int prev2 = 0, prev1 = 0;

    for (int i = 2; i <= cost.size(); i++) {
        int curr = min(prev1 + cost[i - 1],
                       prev2 + cost[i - 2]);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(1)**

------------------------------------------------------------------------

# 📊 Summary

  Approach      Time Complexity   Space Complexity
  ------------- ----------------- ------------------
  Recursion     O(2\^n)           O(n)
  Memoization   O(n)              O(n)
  Tabulation    O(n)              O(n)
  Optimized     O(n)              O(1)

------------------------------------------------------------------------

# 🧠 Key Insight

👉 This is a **DP problem similar to Fibonacci**, but instead of
counting ways, we **minimize cost**.

------------------------------------------------------------------------

# 🎯 Interview Tip

Always explain: Recursion → Memoization → Tabulation → Space
Optimization
