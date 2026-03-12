# Fibonacci Number

## Problem

Given an integer **n**, return the **n-th Fibonacci number**.

The Fibonacci sequence is defined as:

* F(0) = 0
* F(1) = 1
* F(n) = F(n-1) + F(n-2) for n > 1

---

# Approach 1: Recursion (Brute Force)

### Idea

Use the definition of Fibonacci directly.

### Code

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};
```

### Complexity

* Time: **O(2ⁿ)**
* Space: **O(n)** (recursion stack)

---

# Approach 2: Memoization (Top-Down DP)

### Idea

Store already computed Fibonacci values to avoid recomputation.

### Code

```cpp
class Solution {
public:
    int fib(int n, vector<int>& dp) {
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
};
```

### Complexity

* Time: **O(n)**
* Space: **O(n)**

---

# Approach 3: Iterative (Space Optimized)

### Idea

Only keep track of the last two Fibonacci numbers.

### Code

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int prev2 = 0;
        int prev1 = 1;

        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
```

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

# Key Takeaway

Recursion is simple but inefficient.
Dynamic Programming (Memoization or Iteration) reduces complexity to **O(n)**.
