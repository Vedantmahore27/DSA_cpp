# Climbing Stairs Problem (C++)

## 📌 Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb: - 1 step - 2 steps

Find the total number of distinct ways to reach the top.

------------------------------------------------------------------------

## 🔢 Example

Input:\
`n = 3`

Output:\
`3`

Explanation:\
Ways → `(1+1+1), (1+2), (2+1)`

------------------------------------------------------------------------

# 🚀 C++ Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

At each step, you have 2 choices.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
```

### ⏱ Complexity

-   Time: **O(2\^n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 2️⃣ Memoization (Top-Down DP)

### 💡 Idea

Store computed results.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    if (n <= 2) return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 3️⃣ Tabulation (Bottom-Up DP)

### 💡 Idea

Iteratively build solution.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
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

Only last two values needed.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1;
    int prev1 = 2;

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
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

👉 This problem is equivalent to **Fibonacci(n+1)**

------------------------------------------------------------------------

# 🎯 Interview Tip

Always explain progression: Recursion → Memoization → Tabulation → Space
Optimization
