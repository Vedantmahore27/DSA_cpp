# Climbing Stairs Problem

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

# 🚀 Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

At each step, you have 2 choices → take 1 step or 2 steps.

Recurrence: Ways(n) = Ways(n-1) + Ways(n-2)

### 🔁 Code (JavaScript)

``` javascript
function climbStairs(n) {
    if (n <= 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
```

### ⏱ Complexity

-   Time: **O(2\^n)**
-   Space: **O(n)**

### ❌ Drawbacks

-   Recomputes same subproblems
-   Exponential time

------------------------------------------------------------------------

## 2️⃣ Better Approach (Memoization / Top-Down DP)

### 💡 Idea

Store computed results to avoid recomputation.

### 🔁 Code (JavaScript)

``` javascript
function climbStairs(n, dp = {}) {
    if (n <= 2) return n;
    if (dp[n]) return dp[n];

    dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
    return dp[n];
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

### ✅ Advantages

-   Eliminates repeated calculations
-   Much faster

------------------------------------------------------------------------

## 3️⃣ Optimal Approach (Bottom-Up DP / Tabulation)

### 💡 Idea

Build answers iteratively.

### 🔁 Code (JavaScript)

``` javascript
function climbStairs(n) {
    if (n <= 2) return n;

    let dp = new Array(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)**

------------------------------------------------------------------------

## 4️⃣ Most Optimal (Space Optimized)

### 💡 Idea

Only last two values are needed.

### 🔁 Code (JavaScript)

``` javascript
function climbStairs(n) {
    if (n <= 2) return n;

    let prev2 = 1;
    let prev1 = 2;

    for (let i = 3; i <= n; i++) {
        let curr = prev1 + prev2;
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

  ------------------------------------------------------------------------
  Approach         Time         Space           Notes
                   Complexity   Complexity      
  ---------------- ------------ --------------- --------------------------
  Brute Force      O(2\^n)      O(n)            Very slow

  Memoization      O(n)         O(n)            Top-down DP

  Tabulation       O(n)         O(n)            Bottom-up DP

  Space Optimized  O(n)         O(1)            Best solution
  ------------------------------------------------------------------------

------------------------------------------------------------------------

# 🧠 Key Insight

This problem is essentially **Fibonacci**: Ways(n) = Fib(n+1)

------------------------------------------------------------------------

# 🎯 When to Use What?

-   Use **Brute Force** → learning recursion\
-   Use **Memoization** → easier recursion optimization\
-   Use **Tabulation** → iterative DP\
-   Use **Space Optimization** → best for interviews
