# N-Bit Binary Numbers

## Problem
Given a number **N**, generate all binary strings of length **N** such that in every prefix of the string the number of **1's is greater than or equal to the number of 0's**.

### Example

**Input**

```
N = 3
```

**Output**

```
111
110
101
```

### Explanation

For every prefix of the binary string:

```
111  → valid
110  → valid
101  → valid
100  → invalid (zeros become greater than ones)
```

---

# Approach

This problem can be solved using **Recursion and Backtracking**.

### Key Idea

While constructing the binary string:

- We can **always place '1'**
- We can place **'0' only if number of 1's > number of 0's**

This ensures that at any prefix:

```
number_of_1s >= number_of_0s
```

---

# Algorithm

1. Start with string `"1"` because binary string cannot start with `0`.
2. Keep track of:
   - count of **1's**
   - count of **0's**
3. At each recursion step:
   - Add `'1'`
   - Add `'0'` only if `ones > zeros`
4. Stop when string length becomes **N**.

---

# Code (C++)

```cpp
class Solution {
public:

    void solve(int n , string s , vector<string> &res , int one , int zero){
       
        if(s.size() == n){
            res.push_back(s);
            return;
        }

        if(one >= zero){
            s.push_back('1');
            solve(n , s , res , one + 1 , zero);
            s.pop_back();
        }

        if(one > zero){
            s.push_back('0');
            solve(n , s , res , one , zero + 1);
            s.pop_back();
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> res;
        string s = "1";
        solve(n, s, res, 1, 0);
        return res;
    }
};
```

---

# Time Complexity

```
O(2^N)
```

In the worst case we explore all possible binary combinations.

---

# Space Complexity

```
O(N)
```

Recursion stack depth is **N**.

---

# Key Concept

This problem is based on **Backtracking with Constraints**.

Important rule:

```
zeros ≤ ones
```

Similar Problems:

- Generate Parentheses
- Balanced Binary Strings
- Recursion Pattern Problems
