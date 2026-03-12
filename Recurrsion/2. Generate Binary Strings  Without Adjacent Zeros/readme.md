# Generate Valid Binary Strings (No Consecutive Zeros)

## Problem

Given an integer **n**, generate all binary strings of length **n** such that **no two consecutive `0`s appear**.

### Example

```
Input: n = 3

Output:
["010","011","101","110","111"]
```

Explanation:
Binary strings like `"000"` or `"100"` are invalid because they contain **two consecutive zeros**.

---

# Approach: Backtracking

## Idea

We build the string **character by character**.

At every step we have two choices:

* Append `'1'`
* Append `'0'`

But we must follow the constraint:

⚠️ **If the previous character is `0`, we cannot append another `0`.**

So:

* Always allowed → append `'1'`
* Append `'0'` only if:

  * the string is empty OR
  * the last character is `'1'`

---

# Algorithm

1. Start with an empty string.
2. Recursively build the string.
3. If length becomes **n**, store the string in the result.
4. Always try adding `'1'`.
5. Add `'0'` only when the last character is not `'0'`.

---

# C++ Implementation

```cpp
class Solution {
public:
    void solve(vector<string> &ans, int n, string s){
        if(n == 0){
            ans.push_back(s);
            return;
        }

        // append 0 only if previous char is not 0
        if(s.empty() || s.back() != '0')
            solve(ans, n-1, s + "0");

        // append 1 always allowed
        solve(ans, n-1, s + "1");
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(ans, n, "");
        return ans;
    }
};
```

---

# Complexity Analysis

| Metric           | Value                    |
| ---------------- | ------------------------ |
| Time Complexity  | **O(2ⁿ)**                |
| Space Complexity | **O(n)** recursion stack |

The recursion explores all valid binary combinations while pruning invalid ones early.

---

# Key Insight

Instead of generating all **2ⁿ binary strings** and filtering invalid ones, we **prune invalid branches during recursion**, making the solution more efficient.

---

# Pattern

This problem follows the **Backtracking with Constraints** pattern, commonly used in:

* Generate Parentheses
* N-Queens
* Combination Sum
* Subsets with restrictions
