# Generate Parentheses (Backtracking)

## Problem

Given `n` pairs of parentheses, write a function to generate all combinations of **well-formed parentheses**.

### Example

```
Input: n = 3

Output:
[
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
]
```

---

# Approach

This problem is solved using **Backtracking**.

The idea is to build the string step by step while ensuring it always remains **valid**.

We track two values:

* `open` → number of `(` used
* `close` → number of `)` used

### Rules

1. We can add `(` if:

```
open < n
```

2. We can add `)` if:

```
close < open
```

3. When the string length becomes:

```
2 * n
```

it means we formed a valid combination.

---

# Algorithm

1. Start with an empty string.
2. Try adding `(` if allowed.
3. Try adding `)` if allowed.
4. Use **push_back()** to add characters.
5. Use **pop_back()** to undo changes (backtracking).
6. Store valid strings in the result vector.

---

# Optimal C++ Implementation

```cpp
class Solution {
public:
    void solve(int n, vector<string> &ans, string &s, int open, int close){

        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            solve(n, ans, s, open+1, close);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            solve(n, ans, s, open, close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        solve(n, ans, s, 0, 0);

        return ans;
    }
};
```

---

# Time Complexity

The number of valid combinations is given by the **Catalan Number**:

```
Cn = (1 / (n + 1)) * (2n choose n)
```

Approximation:

```
Cn ≈ 4^n / n^(3/2)
```

Since each string has length `2n`, the total complexity becomes:

```
Time Complexity: O(Cn × n)
```

---

# Space Complexity

```
Recursion Stack: O(n)

Result Storage: O(Cn × n)
```

---

# Key Concepts Used

* Backtracking
* Recursion
* Catalan Numbers
* Valid Parentheses Constraint

---

# Why Backtracking Works

Backtracking allows us to **explore all valid combinations while pruning invalid paths early**.

For example:

```
(
((
(())
(()()
...
```

Invalid cases like `")("` are **never generated**, reducing unnecessary work.

---

# Interview Insight

This solution is **optimal** because we must generate **all valid combinations**, which are already `Cn` in number. Therefore the lower bound itself is:

```
Ω(Cn × n)
```

No algorithm can do better than this.

---
