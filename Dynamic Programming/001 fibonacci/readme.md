# Fibonacci Number Problem

## 📌 Problem Statement

Given an integer `n`, return the **n-th Fibonacci number**.

The Fibonacci sequence is defined as:

-   `F(0) = 0`
-   `F(1) = 1`
-   `F(n) = F(n-1) + F(n-2)` for `n >= 2`

------------------------------------------------------------------------

## 🔢 Example

Input:\
`n = 5`

Output:\
`5`

Explanation:\
Sequence → `0, 1, 1, 2, 3, 5`

------------------------------------------------------------------------

# 🚀 Approaches

------------------------------------------------------------------------

## 1️⃣ Brute Force (Recursion)

### 💡 Idea

Directly implement the recursive definition of Fibonacci.

Each function call computes: F(n) = F(n-1) + F(n-2)

### ⚠️ Problem

This leads to **repeated calculations** (overlapping subproblems).

### 🔁 Code (JavaScript)

``` javascript
function fib(n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

### ⏱ Complexity

-   Time: **O(2\^n)** (exponential growth)
-   Space: **O(n)** (recursion stack)

### ❌ Drawbacks

-   Extremely slow for large `n`
-   Redundant computations

------------------------------------------------------------------------

## 2️⃣ Better Approach (Memoization / Top-Down DP)

### 💡 Idea

Store already computed results to avoid recomputation.

### 🔁 Code (JavaScript)

``` javascript
function fib(n, dp = {}) {
    if (n <= 1) return n;
    if (dp[n]) return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
```

### ⏱ Complexity

-   Time: **O(n)**
-   Space: **O(n)** (dp array + recursion stack)

### ✅ Advantages

-   Eliminates redundant calls
-   Much faster than brute force

------------------------------------------------------------------------

## 3️⃣ Optimal Approach (Bottom-Up DP / Tabulation)

### 💡 Idea

Build the solution iteratively from base cases.

### 🔁 Code (JavaScript)

``` javascript
function fib(n) {
    if (n <= 1) return n;

    let dp = new Array(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (let i = 2; i <= n; i++) {
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

We only need the last two values → no need for full array.

### 🔁 Code (JavaScript)

``` javascript
function fib(n) {
    if (n <= 1) return n;

    let prev2 = 0;
    let prev1 = 1;

    for (let i = 2; i <= n; i++) {
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

### ✅ Best Choice

-   Most efficient in both time and space

------------------------------------------------------------------------

# 📊 Summary

  ------------------------------------------------------------------------
  Approach         Time         Space           Notes
                   Complexity   Complexity      
  ---------------- ------------ --------------- --------------------------
  Brute Force      O(2\^n)      O(n)            Very slow, redundant calls

  Memoization      O(n)         O(n)            Top-down DP

  Tabulation       O(n)         O(n)            Bottom-up DP

  Space Optimized  O(n)         O(1)            Best solution
  ------------------------------------------------------------------------

------------------------------------------------------------------------

# 🧠 Key Concepts

-   Recursion
-   Dynamic Programming (DP)
-   Memoization (Top-down)
-   Tabulation (Bottom-up)
-   Space Optimization

------------------------------------------------------------------------

# 🎯 When to Use What?

-   Use **Brute Force** → only for understanding recursion\
-   Use **Memoization** → when recursion is easier to think\
-   Use **Tabulation** → when iterative DP is preferred\
-   Use **Space Optimization** → in interviews (best answer)
