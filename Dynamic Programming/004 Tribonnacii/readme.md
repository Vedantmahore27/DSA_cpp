# Tribonacci Number Problem (C++)

## 📌 Problem Statement

The Tribonacci sequence is defined as:

-   `T(0) = 0`
-   `T(1) = 1`
-   `T(2) = 1`
-   `T(n) = T(n-1) + T(n-2) + T(n-3)` for `n >= 3`

Given an integer `n`, return the **n-th Tribonacci number**.

------------------------------------------------------------------------

## 🔢 Example

Input:\
`n = 4`

Output:\
`4`

Explanation:\
Sequence → `0, 1, 1, 2, 4`

------------------------------------------------------------------------

# 🚀 C++ Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

Direct recursive definition with 3 calls.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;

    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}
```

### ⏱ Complexity

-   Time: **O(3\^n)**
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
    if (n == 0) return 0;
    if (n <= 2) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
}

int tribonacci(int n) {
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

Build solution iteratively.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
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

Only last 3 values needed.

### 🔁 Code

``` cpp
#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;

    int t0 = 0, t1 = 1, t2 = 1;

    for (int i = 3; i <= n; i++) {
        int curr = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = curr;
    }

    return t2;
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(1)**

------------------------------------------------------------------------

# 📊 Summary

  Approach      Time Complexity   Space Complexity
  ------------- ----------------- ------------------
  Recursion     O(3\^n)           O(n)
  Memoization   O(n)              O(n)
  Tabulation    O(n)              O(n)
  Optimized     O(n)              O(1)

------------------------------------------------------------------------

# 🧠 Key Insight

👉 This is an extension of **Fibonacci**, where instead of 2 previous
states, we use **3 previous states**.

------------------------------------------------------------------------

# 🎯 Interview Tip

Always explain progression: Recursion → Memoization → Tabulation → Space
Optimization

Mention: "Fibonacci uses 2 states, Tribonacci uses 3 states --- same DP
pattern."
